[BITS 64]

[GLOBAL acos_fpu_sp_entry]
[GLOBAL acos_fpu_dp_entry]
[GLOBAL acos_fpu_ep_entry]


[section .text]

acos_fpu_sp_entry:

    mov dword [sp_value], edx
    fld dword [sp_value]

    fld st0
    fld st0
    fmul          ; x*x

    fld1
    fsubr         ; 1-(x*x)
    fsqrt         ; sqrt(1-(x*x))
    fxch          ; switch arguments on stack
    fpatan        ; atan(x - sqrt(1-(x*x)))

    fstp dword [sp_value]
    mov edx, dword [sp_value]

    ret


acos_fpu_dp_entry:

    movq qword [dp_value], xmm0
    fld qword [dp_value]

    fld st0
    fld st0
    fmul          ; x*x

    fld1
    fsubr         ; 1-(x*x)
    fsqrt         ; sqrt(1-(x*x))
    fxch          ; switch arguments on stack
    fpatan        ; atan(x - sqrt(1-(x*x)))

    fstp qword [dp_value]
    movq xmm0, qword [dp_value]

    ret


acos_fpu_ep_entry:

    movdqu oword [ep_value], xmm0
    fld tword [ep_value]

    fld st0
    fld st0
    fmul          ; x*x

    fld1
    fsubr         ; 1-(x*x)
    fsqrt         ; sqrt(1-(x*x))
    fxch          ; switch arguments on stack
    fpatan        ; atan(x - sqrt(1-(x*x)))

    fstp tword [sp_value]
    movdqu xmm0, oword [ep_value]

    ret


[section .data]

sp_value dd 0
dp_value dq 0
ep_value do 0.0

