#ifndef PLATFORM_H
#define PLATFORM_H

#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_MSNT
#elif defined(__linux__)
    #define PLATFORM_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
    #define PLATFORM_DARWIN
#else
    #define PLATFORM_UNKNOWN
#endif

#endif // PLATFORM_H