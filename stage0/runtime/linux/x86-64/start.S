.section .text
.globl _start
.extern runtime_entry

_start:
    mov %rsp, %rdi
    and $-16, %rsp
    call runtime_entry
    ud2