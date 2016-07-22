;
;
; File description
;
;


;
;
; Comments required
;
;
[BITS 64]
[GLOBAL memcmp_sse2_entry]



;
;
; !!!!! Function and ABI description !!!!!
;
;


memcmp_sse2_entry:

    test rdx, rdx                ; Let's see if length is zero -> quit
    jz   memcmp_zero_result

    cmp  rdx, 0x01               ; Is there only on byte to compare?
    jle  memcmp_single_byte      ; If so, no SSE2, just simple instructions

    sub rsi, rdi
    mov r10, rdx

    cmp r10, 0x20                ; Check, if we have at least one chunk of 32 bytes
    jge perform_sse2_memcmp      ; If so, use SSE2!


memcmp_chunk_size_left_detection:

    test r10, 0x01              ; More than one byte left?
    jz   memcmp_more_than_one_byte_left

    movzx eax, byte [rdi]
    movzx edx, byte [rdi + rsi]

    sub r10, 0x01
    je  memcmp_single_byte_exit

    add rdi, 0x01
    sub eax, edx
    ret


memcmp_zero_result:

    xor rax, rax               ; Ensure return value is zero
    ret                        ; Leave memcmp operation


memcmp_single_byte:

    movzx eax, byte [rdi]      ; Move byte value from adress hold by rdi to eax and zero extend it
    movzx edx, byte [rsi]      ; Move byte value from adress hold by rsi to edx and zero extend it


memcmp_single_byte_exit:

    sub dword eax, edx
    ret


memcmp_more_than_one_byte_left:

    test r10, 0x02             ; More than two bytes left?
    jz   memcmp_more_than_two_bytes_left

    movzx eax, word [rdi]
    movzx edx, word [rdi + rsi]

    sub r10, 0x02
    je final_calculation

    add rdi, 0x02
    cmp eax, edx
    jnz final_calculation


memcmp_more_than_two_bytes_left:

    test r10, 0x04             ; More than four bytes left?
    jz   memcmp_more_than_four_bytes_left

    mov eax, dword [rdi]
    mov edx, dword [rdi + rsi]

    sub r10, 0x04
    je final_calculation

    add rdi, 0x04
    cmp eax, edx
    jnz final_calculation


memcmp_more_than_four_bytes_left:

    test r8, 0x08             ; More than eight bytes left?
    jz perform_mmx_memcmp

    mov rax, qword [rdi]
    mov rdx, qword [rdi + rsi]

    sub r10, 0x08
    je final_calculation

    add rdi, 0x08
    cmp rax, rbx
    jnz final_calculation


perform_mmx_memcmp:

    movdqu xmm1, [rdi]
    movdqu xmm0, [rdi + rsi]

    pcmpeqb  xmm1, xmm0
    pmovmskb edx, xmm1

    xor eax, eax
    sub edx, 0xFFFF
    jz memcmp_result_return

    bsf dword ecx, edx
    lea rcx, [rdi + rcx]

    movzx eax, byte [rcx]
    movzx edx, byte [rsi + rcx]

    sub eax, edx
    ret


perform_sse2_memcmp:

    mov r11 ,rdx
    add r11, rdi

    mov r8, rdi
    and r8, 0x0F
    jz  sse2_pointer_alignment_okay_16

    movdqu xmm1, [rdi]
    movdqu xmm0, [rdi + rsi]

    pcmpeqb  xmm1, xmm0
    pmovmskb edx, xmm1
    
    sub edx, 0xFFFF
    jnz sse2_prestage_memcmp_mismatch

    neg r8
    lea rdi, [16 + rdi + r8]


sse2_pointer_alignment_okay_16:

    ; Still todo


sse2_prestage_memcmp_mismatch:

    bsf dword ecx, edx
    movzx eax, byte [rdi + rcx]

    add rsi, rdi
    movzx edx, byte [rsi + rcx]

    sub dword eax, edx
    ret


memcmp_result_return:

    ret                        ; Leave memcmp operation


final_calculation:

    cmp rax, rdx
    jz memcmp_zero_result

    mov r11, rax
    sub r11, rdx
    
    bsf qword rcx, r11
    sar qword rcx, 0x03
    sal qword rcx, 0x03

    sar qword rax, cl
    movzx eax, byte al

    sar qword rdx, cl
    movzx edx, byte dl

    sub eax, edx
    ret
