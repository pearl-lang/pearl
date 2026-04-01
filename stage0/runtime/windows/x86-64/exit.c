#include <winh.h>

_Noreturn void sys_exit(int code) {
	ExitProcess((unsigned int)code);
	for (;;) {
	}
}