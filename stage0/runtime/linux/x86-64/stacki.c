#include <platform.h>

void initialize_from_stack(void *stack_top, struct platform_startup *out) {
	platform_initialize_from_stack(stack_top, out);
}

char **get_envp(void) {
	return platform_get_envp();
}

char *getenv(const char *key) {
	return platform_getenv(key);
}