;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; stdlib.asm
;
; This file contains all x86_64 "fast path" implementations of stdlib.h
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
[GLOBAL abs_entry]
[GLOBAL abs64_entry]


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Code section
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[section .text]


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; This is the entry point of the x64 asm version of abs. It can be executed on
; any x86_64 cpu.
;
; Input registers:
;
;  - eax must contain the input value for calculation
;
;
; Return values:
;
;  - The return value will be stored in rax
;
;
; Affected / trashed registers:
;
;  This routine uses (and modifies!) the registers: eax and edx. Don't store
;  data in these registers you need to rely on later.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

abs_entry:
    mov eax, edi
    cdq
    xor eax, edx
    sub eax, edx
    ret


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; This is the entry point of the x64 asm version of (l)labs. It can be executed on
; any x86_64 cpu.
;
; Input registers:
;
;  - rax must contain the input value for calculation
;
;
; Return values:
;
;  - The return value will be stored in rax
;
;
; Affected / trashed registers:
;
;  This routine uses (and modifies!) the registers: rax and rdx. Don't store
;  data in these registers you need to rely on later.
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
abs64_entry:
    mov rax, rdi
    cqo
    xor rax, rdx
    sub rax, rdx
    ret
