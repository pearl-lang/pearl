#ifndef WINH_H
#define WINH_H

#if defined(_MSC_VER)

#define WINH_STDCALL __stdcall
#define WINH_DLLIMPORT __declspec(dllimport)

#elif (defined(__GNUC__) || defined(__clang__)) && defined(_WIN32)

#define WINH_STDCALL __attribute__((stdcall))
#define WINH_DLLIMPORT __attribute__((dllimport))
#else
#define WINH_STDCALL
#define WINH_DLLIMPORT

#endif

WINH_DLLIMPORT char *WINH_STDCALL GetCommandLineA(void);
WINH_DLLIMPORT char *WINH_STDCALL GetEnvironmentStringsA(void);
WINH_DLLIMPORT int WINH_STDCALL FreeEnvironmentStringsA(char *env);
WINH_DLLIMPORT _Noreturn void WINH_STDCALL ExitProcess(unsigned int code);

#undef WINH_STDCALL
#undef WINH_DLLIMPORT

#endif // WINH_H