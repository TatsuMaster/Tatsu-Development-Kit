;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; string.asm
;
; This file contains all x86_64 "fast path" implementations of string.h
; functions.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Define section as 64 bit area and export all labels, which needs to
; be accessed in c programming language. All labels not listed as "global"
; won't be accessable outside of this file.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[BITS 64]
[GLOBAL memcmp_sse2_entry]



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; This is the entry point of the SSE2 version of memcmp. It can be executed on
; any x86_64 cpu. It doesn't matter which generation it is, because every
; x86_64 system needs to support at least SSE2.
;
; This implementation takes advantage of using the movdqa / movdqu instructions
; available in SSE2 as far as pcmpeqb and pmovmskb. Take a look at the comments
; for more information.
;
; Input registers:
;
;  - rsi: Pointer to first memory region
;  - rdi: Pointer to second memory region
;  - rdx: Number of bytes to compare
;
;
; Return values:
;
;  - The return value (difference of code points) will be stored in rax
;
;
; Affected / trashed registers:
;
;  This routine uses (and modifies!) the registers: rax, rcx, rdx, rsi, rdi
;  r8, r10, r11, xmm0 and xmm1. Don't store data in these registers you need
;  to rely on later.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

memcmp_sse2_entry:

    test rdx, rdx                      ; Let's see if length is zero -> quit
    jz   memcmp_zero_result

    cmp  rdx, 0x01                     ; Is there only on byte to compare?
    jle  memcmp_single_byte            ; If so, no SSE2, just simple instructions

    sub rsi, rdi                       ; Calculate difference of pointers. We use this later
    mov r10, rdx                       ; for indirect addressing. So just one pointer needs to be
                                       ; incremented.

    cmp r10, 0x20                      ; Check, if we have at least one chunk of 32 bytes
    jge perform_sse2_memcmp            ; If so, use SSE2!


memcmp_chunk_size_left_detection:

    test r10, 0x01                     ; More than one byte left? -> Jump to faster version
    jz   memcmp_more_than_one_byte_left

    movzx eax, byte [rdi]              ; Load both bytes into registers and compare them
    movzx edx, byte [rdi + rsi]

    sub r10, 0x01
    je  memcmp_single_byte_exit

    add rdi, 0x01
    sub eax, edx
    ret


memcmp_zero_result:

    xor rax, rax                       ; Ensure return value is zero
    ret                                ; Leave memcmp operation


memcmp_single_byte:

    movzx eax, byte [rdi]              ; Move byte value from adress to register and zero extend it
    movzx edx, byte [rsi]              ; see above


memcmp_single_byte_exit:

    sub dword eax, edx                 ; Calculate difference of both bytes
    ret                                ; and return


memcmp_more_than_one_byte_left:

    test r10, 0x02                     ; More than two bytes left? -> Jump to faster version
    jz   memcmp_more_than_two_bytes_left

    movzx eax, word [rdi]              ; Load both words (= 2 bytes) into registers and compare them
    movzx edx, word [rdi + rsi]

    sub r10, 0x02
    je final_calculation

    add rdi, 0x02
    cmp eax, edx
    jnz final_calculation


memcmp_more_than_two_bytes_left:

    test r10, 0x04                     ; More than four bytes left? -> Jump to faster version
    jz   memcmp_more_than_four_bytes_left

    mov eax, dword [rdi]               ; Load both dwords (= 4 bytes) into registers and
    mov edx, dword [rdi + rsi]         ; compare them

    sub r10, 0x04
    je final_calculation

    add rdi, 0x04
    cmp eax, edx
    jnz final_calculation


memcmp_more_than_four_bytes_left:

    test r8, 0x08                      ; More than eight bytes left? -> Use MMX instructions!
    jz perform_mmx_memcmp

    mov rax, qword [rdi]               ; Load both qwords (= 8 bytes) into registers and
    mov rdx, qword [rdi + rsi]         ; compare them

    sub r10, 0x08
    je final_calculation

    add rdi, 0x08
    cmp rax, rbx
    jnz final_calculation


perform_mmx_memcmp:                    ; Here it get's fast (but not fastest)!

    movdqu xmm1, [rdi]                 ; Move Unaligned Double Quad Word
    movdqu xmm0, [rdi + rsi]           ; Load both ywords (= 16 bytes) into MMX registers

    pcmpeqb  xmm1, xmm0                ; Packed Compare For Equal
    pmovmskb edx, xmm1                 ; Move Byte Mask

    xor eax, eax                       ; Reset eax and check if we're done right now!
    sub edx, 0xFFFF
    jz memcmp_result_return

    bsf dword ecx, edx                 ; If not, Bit Scan Forward and do further compares
    lea rcx, [rdi + rcx]

    movzx eax, byte [rcx]              ; Load values left to non mmx Registers
    movzx edx, byte [rsi + rcx]

    sub eax, edx                       ; Calculate difference and return
    ret


perform_sse2_memcmp:                   ; Okay, this is the real deal for fast comparisons!

    mov r11 ,rdx
    add r11, rdi

    mov r8, rdi                        ; If alignment is okay, we can use faster instructions
    and r8, 0x0F
    jz  sse2_pointer_alignment_okay_16

    movdqu xmm1, [rdi]                 ; If not, do the "normal" MMX compare (see above)
    movdqu xmm0, [rdi + rsi]

    pcmpeqb  xmm1, xmm0
    pmovmskb edx, xmm1

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    neg r8
    lea rdi, [16 + rdi + r8]           ; Load aligned part of given pointer(s)


sse2_pointer_alignment_okay_16:

    test rsi, 0x0F                     ; Check for another fast path we could take
    jz sse2_memcmp_fast

    test rdi, 0x10                     ; Check if we even could take 32 bit aligned fast path
    jz sse2_pointer_alignment_okay_32

    movdqu xmm0, [rdi + rsi]           ; Compare using MMX registers (see above)
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Increment pointer


sse2_pointer_alignment_okay_32:

    mov r10, r11
    and r10, -0x20

    cmp rdi, r10
    jge sse2_match_16_memcmp           ; Check if we even could take 64 bit aligned fast path

    test rdi, 0x20
    jz sse2_pointer_alignment_okay_64

    movdqu xmm0, [rdi + rsi]           ; If not, break down into single ywords and compare using
    pcmpeqb xmm0, [rdi]                ; mmx registers
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Increment pointer and analyze next 16 bytes
    movdqu xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Increment pointer


sse2_pointer_alignment_okay_64:

    mov r10, r11
    and r10, -0x40

    cmp rdi, r10
    jge sse2_match_32_memcmp           ; Can we take a faster path or do we need to unrole?


perform_aligned_64_memcmp:

    movdqu xmm0, [rdi + rsi]           ; Break down into four segments and compare using mmx
    pcmpeqb xmm0, [rdi]                ; registers
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10
    movdqu xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10
    movdqu xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb  edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10
    movdqu xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb  edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10
    cmp r10, rdi
    jne perform_aligned_64_memcmp      ; Not compared everything yet? Move forward...


sse2_match_32_memcmp:

    mov r10, r11
    and r10, -0x20

    cmp rdi, r10                       ; Should we use the 32 or 16 bit path?
    jge sse2_match_16_memcmp


sse2_perform_32_memcmp:

    movdqu xmm0, [rdi + rsi]           ; Break down into four segments and compare using mmx
    pcmpeqb xmm0, [rdi]                ; registers
    pmovmskb  edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Move to next 16 bytes
    movdqu xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb  edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10
    cmp r10, rdi
    jne sse2_perform_32_memcmp         ; Not compared everything yet? Move forward...


sse2_match_16_memcmp:

    sub r11, rdi
    je memcmp_zero_result             ; If everything was equal, return 0

    mov r10, r11                      ; Not finished yet! Calc chunk size left and start all over
    jmp memcmp_chunk_size_left_detection


sse2_memcmp_fast:

    mov r10, r11
    and r10, -0x20

    cmp rdi, r10
    jge sse2_match_16_memcmp

    test rdi, 0x10
    jz sse2_memcmp_fast_32

    movdqa xmm0, [rdi + rsi]           ; Move Unaligned Double Quad Word. Better than unaligned
    pcmpeqb xmm0, [rdi]                ; version used in slower paths
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue
    cmp r10, rdi
    je sse2_match_16_memcmp


sse2_memcmp_fast_32:                   ; If you've read until here, you should know all the patterns
                                       ; occuring in this listing
    mov r10, r11
    and r10, -0x40

    test rdi, 0x20
    jz sse2_memcmp_fast_64

    movdqa xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue
    movdqa xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue


sse2_memcmp_fast_64:

    cmp r10, rdi
    je sse2_match_32_memcmp


sse2_memcmp_fast_64_perform:

    movdqa xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue
    movdqa xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue
    movdqa xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue
    movdqa xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue
    cmp r10, rdi
    jne sse2_memcmp_fast_64_perform

    mov r10, r11
    and r10, -0x20

    cmp rdi, r10
    jge sse2_match_16_memcmp


sse2_memcmp_fast_result:

    movdqa xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue
    movdqa xmm0, [rdi + rsi]
    pcmpeqb xmm0, [rdi]
    pmovmskb edx, xmm0

    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch  ; Missmatch detected?

    add rdi, 0x10                      ; Incremente pointer and continue
    cmp rdi, r10
    jne sse2_memcmp_fast_result

    sub r11, rdi
    je memcmp_zero_result              ; Everything equal? Let's get out of here...

    mov r10, r11                       ; Not finished yet! Calc chunk size left and start all over
    jmp memcmp_chunk_size_left_detection


sse2_prestage_memcmp_mismatch:         ; Missmatch occured! Calculate difference and return

    bsf dword ecx, edx
    movzx eax, byte [rdi + rcx]

    add rsi, rdi
    movzx edx, byte [rsi + rcx]

    sub dword eax, edx
    ret


memcmp_result_return:

    ret                                ; Leave memcmp operation


final_calculation:                     ; Let's check, which byte failed during comparison

    cmp rax, rdx
    jz memcmp_zero_result              ; Everything equal? Let's get out of here...

    mov r11, rax
    sub r11, rdx

    bsf qword rcx, r11                 ; Bit Scan Forward and shift through the whole qword
    sar qword rcx, 0x03                ; to find non matching parts!
    sal qword rcx, 0x03

    sar qword rax, cl                  ; Load first byte to calculate difference
    movzx eax, byte al

    sar qword rdx, cl                  ; Load second byte to calculate difference
    movzx edx, byte dl

    sub eax, edx                       ; Calculate difference and return
    ret
