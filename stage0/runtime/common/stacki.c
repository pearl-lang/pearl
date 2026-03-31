#include <platform.h>

static char **g_runtime_envp;

char **platform_get_envp(void) {
	return g_runtime_envp;
}

char *platform_getenv(const char *key) {
	char **envp = g_runtime_envp;
	if (key == (const char *)0 || envp == (char **)0) {
		return (char *)0;
	}

	for (; *envp != (char *)0; ++envp) {
		const char *k = key;
		char *e = *envp;

		while (*k != '\0' && *e == *k) {
			++k;
			++e;
		}

		if (*k == '\0' && *e == '=') {
			return e + 1;
		}
	}

	return (char *)0;
}

void platform_initialize_from_stack(void *stack_top, struct platform_startup *out) {
	long argc = *(long *)stack_top;
	char **argv = (char **)((long *)stack_top + 1);

	out->argc = (int)argc;
	out->argv = argv;
	out->envp = argv + argc + 1;
	g_runtime_envp = out->envp;
}