#ifndef PLATFORM_H
#define PLATFORM_H

struct platform_startup {
	int argc;
	char **argv;
	char **envp;
};

void platform_initialize_from_stack(void *stack_top, struct platform_startup *out);
void initialize_from_stack(void *stack_top, struct platform_startup *out);
void platform_set_envp(char **envp);
char **platform_get_envp(void);
char **get_envp(void);
char *platform_getenv(const char *key);
char *getenv(const char *key);
_Noreturn void sys_exit(int code);

#endif // PLATFORM_H