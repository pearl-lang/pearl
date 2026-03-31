extern _Noreturn void runtime_entry(void *stack_top);

void mainCRTStartup(void) {
	runtime_entry((void *)0);
}

void _start(void) {
	mainCRTStartup();
}