[BITS 64]

[GLOBAL acos_fpu_sp_entry]
[GLOBAL acos_fpu_dp_entry]
[GLOBAL acos_fpu_ep_entry]


acos_fpu_sp_entry:

    jmp acos_fpu_calc_result


acos_fpu_dp_entry:

    nop

    jmp acos_fpu_calc_result


acos_fpu_ep_entry:

    nop


acos_fpu_calc_result:

    nop

    ret
