#ifndef SYSCALLW_H
#define SYSCALLW_H

#if defined(__x86_64__) && defined(__linux__)
extern _Noreturn void sys_exit(int code);
#elif defined(__x86_64__) && defined(__APPLE__)
extern _Noreturn void sys_exit(int code);
#elif defined(_WIN32) && defined(__x86_64__)
extern _Noreturn void sys_exit(int code);
#else
static inline _Noreturn void sys_exit(int code) {
	(void)code;
	for (;;) {
	}
}
#endif

#endif // SYSCALLW_H