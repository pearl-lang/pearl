#include <platform.h>

void platform_initialize_from_stack(void *stack_top, struct platform_startup *out) {
	long argc = *(long *)stack_top;
	char **argv = (char **)((long *)stack_top + 1);

	out->argc = (int)argc;
	out->argv = argv;
	out->envp = argv + argc + 1;
	platform_set_envp(out->envp);
}

void initialize_from_stack(void *stack_top, struct platform_startup *out) {
	platform_initialize_from_stack(stack_top, out);
}

char **get_envp(void) {
	return platform_get_envp();
}

char *getenv(const char *key) {
	return platform_getenv(key);
}
