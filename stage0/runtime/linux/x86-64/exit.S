.section .text
.global sys_exit

sys_exit:
	mov $60, %rax
	syscall
	ret
