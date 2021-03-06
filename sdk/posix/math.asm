;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; math.asm
;
; This file contains all x86_64 "fast path" implementations of math.h
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

[GLOBAL acos_fpu_sp_entry]
[GLOBAL acos_fpu_dp_entry]
[GLOBAL acos_fpu_ep_entry]


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Code section
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[section .text]


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; This is the entry point of the x64 asm version of acosf. It can be executed
; on any x86_64 cpu.
;
; Input registers:
;
;  - mmx0 must contain the input value for calculation
;
;
; Return values:
;
;  - The return value will be stored in mmx0
;
;
; Affected / trashed registers:
;
;  This routine uses (and modifies!) the registers: mmx0 and st0. Don't store
;  data in these registers you need to rely on later.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
acos_fpu_sp_entry:

    mov dword [sp_value], edx         ; Load edx value into memory
    fld dword [sp_value]              ; Load memory value into FPU

    fld st0                           ; Push st(0)
    fld st0                           ; Push st(0) => st(0) and st(1) holding the same value now

    fmul                              ; st(1) times st(0), store result in st(0) => (x * x)

    fld1                              ; Push 1.0
    fsubr                             ; Substract reverse: st(1) - st(0) => (x*x) - 1
    fsqrt                             ; Square Root ((x*x)-1)
    fxch                              ; Switch arguments on stack
    fpatan                            ; atan(sqrt(1-(x*x)) / 1)

    fstp dword [sp_value]             ; Store result value in memory
    mov edx, dword [sp_value]         ; Store result in edx

    ret                               ; Return to caller


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; This is the entry point of the x64 asm version of acos. It can be executed on
; any x86_64 cpu.
;
; Input registers:
;
;  - mmx0 must contain the input value for calculation
;
;
; Return values:
;
;  - The return value will be stored in mmx0
;
;
; Affected / trashed registers:
;
;  This routine uses (and modifies!) the registers: mmx0 and st0. Don't store
;  data in these registers you need to rely on later.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
acos_fpu_dp_entry:

    movq qword [dp_value], xmm0       ; Load xmm0 value into memory
    fld qword [dp_value]              ; Load memory value into FPU

    fld st0                           ; Push st(0)
    fld st0                           ; Push st(0) => st(0) and st(1) holding the same value now

    fmul                              ; st(1) times st(0), store result in st(0) => (x * x)

    fld1                              ; Push 1.0
    fsubr                             ; Substract reverse: st(1) - st(0) => (x*x) - 1
    fsqrt                             ; Square Root ((x*x)-1)
    fxch                              ; Switch arguments on stack
    fpatan                            ; atan(sqrt(1-(x*x)) / 1)

    fstp qword [dp_value]             ; Store result value in memory
    movq xmm0, qword [dp_value]       ; Store result in xmm0

    ret                               ; Return to caller


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; This is the entry point of the x64 asm version of acosl. It can be executed
; on any x86_64 cpu.
;
; Input registers:
;
;  - mmx0 must contain the input value for calculation
;
;
; Return values:
;
;  - The return value will be stored in mmx0
;
;
; Affected / trashed registers:
;
;  This routine uses (and modifies!) the registers: mmx0 and st0. Don't store
;  data in these registers you need to rely on later.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
acos_fpu_ep_entry:

    movdqu oword [ep_value], xmm0     ; Load xmm0 value into memory
    fld tword [ep_value]              ; Load memory value into FPU

    fld st0                           ; Push st(0)
    fld st0                           ; Push st(0) => st(0) and st(1) holding the same value now
    fmul                              ; st(1) times st(0), store result in st(0) => (x * x)

    fld1                              ; Push 1.0
    fsubr                             ; Substract reverse: st(1) - st(0) => (x*x) - 1
    fsqrt                             ; Square Root ((x*x)-1)
    fxch                              ; switch arguments on stack
    fpatan                            ; atan(x - sqrt(1-(x*x)))

    fstp tword [ep_value]             ; Store result value in memory
    movdqu xmm0, oword [ep_value]     ; Store result in xmm0

    ret                               ; Return to caller


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Data section
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[section .data]

sp_value dd 0
dp_value dq 0
ep_value do 0.0

