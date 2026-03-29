#include "platform.h"

extern int main(int argc, char **argv);

static _Noreturn void runtime_entry(void *stack_top) {
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
void _start(void) {
	void *stack_top;
	__asm__ volatile("mov %%rsp, %0" : "=r"(stack_top));
	runtime_entry(stack_top);
}
#endif
