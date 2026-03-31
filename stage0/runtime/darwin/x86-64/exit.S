.section __TEXT,__text
.global _sys_exit

_sys_exit:
    mov $0x2000001, %rax
    syscall