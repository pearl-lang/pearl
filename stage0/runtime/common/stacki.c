#include <platform.h>

static char **g_runtime_envp;

char **platform_get_envp(void) {
	return g_runtime_envp;
}

void platform_set_envp(char **envp) {
	g_runtime_envp = envp;
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