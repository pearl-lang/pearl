#include "platform.h"

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

#if defined(_WIN32)

__declspec(dllimport) char *__stdcall GetCommandLineA(void);
__declspec(dllimport) char *__stdcall GetEnvironmentStringsA(void);
__declspec(dllimport) int __stdcall FreeEnvironmentStringsA(char *env);
__declspec(dllimport) void __stdcall ExitProcess(unsigned int code);

static char g_cmdline_copy[32768];
static char *g_argv[256];
static char g_env_copy[65536];
static char *g_envp[1024];

static int platform_is_space(char ch) {
	return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

static int platform_parse_cmdline(char *buf, char **argv, int argv_cap) {
	int argc = 0;
	char *p = buf;

	while (*p != '\0') {
		while (platform_is_space(*p)) {
			++p;
		}
		if (*p == '\0') {
			break;
		}

		if (argc + 1 >= argv_cap) {
			break;
		}

		char *dst = p;
		int in_quotes = 0;
		argv[argc++] = dst;

		while (*p != '\0') {
			int backslashes = 0;

			while (*p == '\\') {
				++backslashes;
				++p;
			}

			if (*p == '"') {
				int i;
				for (i = 0; i < backslashes / 2; ++i) {
					*dst++ = '\\';
				}

				if ((backslashes & 1) != 0) {
					*dst++ = '"';
					++p;
					continue;
				}

				if (in_quotes && p[1] == '"') {
					*dst++ = '"';
					p += 2;
					continue;
				}

				in_quotes = !in_quotes;
				++p;
				continue;
			}

			while (backslashes-- > 0) {
				*dst++ = '\\';
			}

			if (*p == '\0' || (!in_quotes && platform_is_space(*p))) {
				break;
			}

			*dst++ = *p++;
		}

		*dst = '\0';

		while (platform_is_space(*p)) {
			++p;
		}
	}

	argv[argc] = (char *)0;
	return argc;
}

static char **platform_build_envp(void) {
	char *src = GetEnvironmentStringsA();
	int i = 0;
	int envc = 0;
	char *cursor;

	if (src == (char *)0) {
		g_envp[0] = (char *)0;
		return g_envp;
	}

	while (i + 1 < (int)sizeof(g_env_copy)) {
		g_env_copy[i] = src[i];
		if (src[i] == '\0' && src[i + 1] == '\0') {
			g_env_copy[i + 1] = '\0';
			break;
		}
		++i;
	}

	if (i + 1 >= (int)sizeof(g_env_copy)) {
		g_env_copy[sizeof(g_env_copy) - 2] = '\0';
		g_env_copy[sizeof(g_env_copy) - 1] = '\0';
	}

	FreeEnvironmentStringsA(src);

	cursor = g_env_copy;
	while (*cursor != '\0' && envc + 1 < (int)(sizeof(g_envp) / sizeof(g_envp[0]))) {
		g_envp[envc++] = cursor;
		while (*cursor != '\0') {
			++cursor;
		}
		++cursor;
	}

	g_envp[envc] = (char *)0;
	return g_envp;
}

void platform_initialize_from_stack(void *stack_top, struct platform_startup *out) {
	(void)stack_top;

	char *src = GetCommandLineA();
	int i = 0;
	while (src[i] != '\0' && i < (int)(sizeof(g_cmdline_copy) - 1)) {
		g_cmdline_copy[i] = src[i];
		++i;
	}
	g_cmdline_copy[i] = '\0';

	out->argc = platform_parse_cmdline(g_cmdline_copy, g_argv, (int)(sizeof(g_argv) / sizeof(g_argv[0])));
	out->argv = g_argv;
	out->envp = platform_build_envp();
	g_runtime_envp = out->envp;
}

_Noreturn void platform_exit(int code) {
	ExitProcess((unsigned int)code);
	for (;;) {
	}
}

#else

void platform_initialize_from_stack(void *stack_top, struct platform_startup *out) {
	long argc = *(long *)stack_top;
	char **argv = (char **)((long *)stack_top + 1);

	out->argc = (int)argc;
	out->argv = argv;
	out->envp = argv + argc + 1;
	g_runtime_envp = out->envp;
}

_Noreturn void platform_exit(int code) {
#if defined(__x86_64__) && defined(__linux__)
	__asm__ volatile(
		"mov %0, %%rdi\n\t"
		"mov $60, %%rax\n\t"
		"syscall"
		:
		: "r"((long)code)
		: "rax", "rdi", "rcx", "r11", "memory");
#elif defined(__x86_64__) && defined(__APPLE__)
	__asm__ volatile(
		"mov %0, %%rdi\n\t"
		"mov $0x2000001, %%rax\n\t"
		"syscall"
		:
		: "r"((long)code)
		: "rax", "rdi", "rcx", "r11", "memory");
#else
	(void)code;
	for (;;) {
	}
#endif

	__builtin_unreachable();
}

#endif
