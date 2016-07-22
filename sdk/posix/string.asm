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

    ; ÜBERDENKEN, was hier hin kommt!


memcmp_zero_result:

    xor rax, rax               ; Ensure return value is zero
    ret                        ; Leave memcmp operation


memcmp_single_byte:

    movzx eax, byte [rdi]      ; Move byte value from adress hold by rdi to eax and zero extend it
    movzx edx, byte [rsi]      ; Move byte value from adress hold by rsi to edx and zero extend it

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

    ;test r8, 0x08             ; More than eight bytes left?
    ;jz perform_mmx_memcmp

    ;mov rax, qword [rcx]
    ;mov rbx, qword [rdx]

    ;sub r8, 0x08
    ;je final_calculation

    ;add rcx, 0x08
    ;add rdx, 0x08

    ;cmp rax, rbx
    ;jnz final_calculation


perform_mmx_memcmp:

    ;movdqu xmm1, [rdx]
    ;movdqu xmm0, [rcx]

    ;pcmpeqb  xmm1, xmm0
    ;pmovmskb ebx, xmm1

    ;xor eax, eax
    ;sub ebx, 0xFFFF
    ;jz memcmp_result_return

    ;bsf dword ecx, ebx
    ;lea rcx, [rdx]
    ;movzx eax, byte [rcx]
    ;movzx ebx, byte [rdx]
    ;sub   eax, edx
    ;ret


perform_sse2_memcmp:


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
