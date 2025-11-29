#ifndef UTILS_H
#define UTILS_H

#include "platform.h"

void die(const char *message);

#if defined(PLATFORM_WINDOWS)
    char* resolve_path(const char *path);
#elif defined(PLATFORM_LINUX) || defined(PLATFORM_MACOS)
    char* resolve_path(const char *path);
#endif

#endif // UTILS_H