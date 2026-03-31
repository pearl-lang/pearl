#include <platform.h>

extern void platform_initialize_from_stack(void *stack_top, struct platform_startup *out);

void initialize_from_stack(void *stack_top, struct platform_startup *out) {
	platform_initialize_from_stack(stack_top, out);
}