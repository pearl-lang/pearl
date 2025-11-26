#ifndef PLATFORM_H
#define PLATFORM_H

typedef enum {
    PLATFORM_MSNT,
    PLATFORM_LINUX,
    PLATFORM_DARWIN,
    PLATFORM_UNKNOWN
} platform_t;

typedef enum {
    ARCH_X86_64,
    ARCH_X86,
    ARCH_ARM64,
    ARCH_ARM,
    ARCH_UNKNOWN
} architecture_t;

typedef struct {
    platform_t platform;
    architecture_t architecture;
} system_info_t;

// Detect current platform
#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_MSNT 1
#elif defined(__linux__)
    #define PLATFORM_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
    #define PLATFORM_DARWIN 1
#else
    #define PLATFORM_UNKNOWN 1
#endif

// Detect cpu architecture
#if defined(__x86_64__) || defined(_M_X64)
    #define ARCH_X86_64 1
#elif defined(__i386__) || defined(_M_IX86)
    #define ARCH_X86 1
#elif defined(__aarch64__)
    #define ARCH_ARM64 1
#elif defined(__arm__) || defined(_M_ARM)
    #define ARCH_ARM 1
#else
    #define ARCH_UNKNOWN 1
#endif

char* get_platform();
char* get_architecture();
system_info_t get_system_info();

#endif // PLATFORM_H