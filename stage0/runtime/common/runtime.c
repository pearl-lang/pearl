#include <platform.h>
#include <syscallw.h>

extern int main(int argc, char **argv);

_Noreturn void runtime_entry(void *stack_top) {
	struct platform_startup startup;

    initialize_from_stack(stack_top, &startup);
	sys_exit(main(startup.argc, startup.argv));
}