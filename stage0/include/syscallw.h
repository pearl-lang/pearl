#ifndef SYSCALLW_H
#define SYSCALLW_H

#if defined(__x86_64__) && defined(__linux__)

extern void sys_exit(int code) __attribute__((noreturn));

#elif defined(__x86_64__) && defined(__APPLE__)

extern void sys_exit(int code) __attribute__((noreturn));

#else

(void)code;
for (;;) {
}

#endif

#endif // SYSCALLW_H