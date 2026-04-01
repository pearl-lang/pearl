#include <platform.h>

extern int main(int argc, char **argv);

_Noreturn void runtime_entry(void *stack_top) {
	struct platform_startup startup;
	platform_initialize_from_stack(stack_top, &startup);
	platform_exit(main(startup.argc, startup.argv));
}

#if defined(_WIN32)
void mainCRTStartup(void) {
	runtime_entry((void *)0);
}

void _start(void) {
	mainCRTStartup();
}
#else
__attribute__((noreturn, naked)) void _start(void) {
	__asm__ volatile(
		"mov %rsp, %rdi\n\t"
		"and $-16, %rsp\n\t"
		"call runtime_entry\n\t"
		"ud2");
}
#endif
