;
;
; !!!!! Function and ABI description !!!!!
;
;
[BITS 64]
[GLOBAL memcmp_sse2_entry]


memcmp_sse2_entry:

    test r8, r8                ; Let's see if length is zero -> quit
    jz   memcmp_zero_result

    cmp  r8, 0x01              ; Is there only on byte to compare?
    je   memcmp_single_byte    ; If so, no SSE2, just simple instructions

    cmp  r8, 0x20              ; Check, if we have at least one chunk of 32 bytes
    jge  perform_sse2_memcmp   ; If so, use SSE2!


memcmp_chunk_size_left_detection:

    test r8, 0x01             ; More than one byte left?
    jz   memcmp_more_than_one_byte_left

    ; ÜBERDENKEN, was hier hin kommt!


memcmp_zero_result:

    xor rax, rax               ; Ensure return value is zero
    ret                        ; Leave memcmp operation


memcmp_single_byte:

    movzx eax, byte [rcx]      ; Move byte value from adress hold by rcx to eax and zero extend it
    movzx ebx, byte [rdx]      ; Move byte value from adress hold by rdx to ebx and zero extend it

    sub eax, ebx
    ret


memcmp_more_than_one_byte_left:

    test r8, 0x02             ; More than two bytes left?
    jz   memcmp_more_than_two_bytes_left

    movzx eax, word [rcx]
    movzx ebx, word [rdx]

    sub r8, 0x02
    je  final_calculation

    add rcx, 0x02
    add rdx, 0x02

    cmp eax, ebx
    jnz final_calculation


memcmp_more_than_two_bytes_left:

    test r8, 0x04             ; More than four bytes left?
    jz   memcmp_more_than_four_bytes_left

    mov eax, dword [rcx]
    mov ebx, dword [rdx]

    sub r8, 0x04
    je final_calculation

    add rcx, 0x04
    add rdx, 0x04

    cmp eax, ebx
    jnz final_calculation


memcmp_more_than_four_bytes_left:

    test r8, 0x08             ; More than eight bytes left?
    jz perform_mmx_memcmp

    mov rax, qword [rcx]
    mov rbx, qword [rdx]


    sub r8, 0x08
    je final_calculation


    add rcx, 0x08
    add rdx, 0x08

    cmp rax, rbx
    jnz final_calculation


perform_mmx_memcmp:

    movdqu xmm1, [rdx, rcx]
    movdqu xmm0, [rcx]

    pcmpeqb  xmm1, xmm0
    pmovmskb ebx, xmm1

    xor eax, eax
    sub ebx, 0xFFFF
    jz memcmp_result_return

    bsf dword ecx, ebx
    lea rcx, [rdx]
    movzx eax, byte [rcx]
    movzx ebx, byte [rdx]
    sub   eax, edx
    ret



;  83         movzbl   (%rcx), %eax
;  84         movzbl   (%rsi, %rcx), %edx
;  85         jmp      L(finz1)


perform_sse2_memcmp:


memcmp_result_return:

    ret                        ; Leave memcmp operation


final_calculation:

    ;cmp rax, r8
    ;jz memcmp_zero_result
    
    cmp eax, ebx
    je  memcmp_zero_result
    
    mov rax, 1337
    
    ;mov r11, rax
    ;sub r11, r8
    
    ;bsf rcx, r11
    ;sar rcx, 0x03
    ;sal rcx, 0x03
    ;sar rax, cl

    ;movzx eax, al

    ;sar r8, cl
    ;mov rdx, r8

    ;movzx edx, byte dl
    ;sub eax, ebx

    ret
