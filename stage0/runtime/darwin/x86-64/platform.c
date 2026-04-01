#include <platform.h>

void platform_initialize_from_stack(void *stack_top, struct platform_startup *out) {
	long argc = *(long *)stack_top;
	char **argv = (char **)((long *)stack_top + 1);

	out->argc = (int)argc;
	out->argv = argv;
	out->envp = argv + argc + 1;
	platform_set_envp(out->envp);
}
