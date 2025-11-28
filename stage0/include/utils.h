#ifndef UTILS_H
#define UTILS_H

#include "platform.h"

void die(const char *message);

// #if defined(PLATFORM_LINUX) || defined(PLATFORM_DARWIN)
//     #include <unistd.h>
//     char* read_symlink_unix(const char *path);
// #elif defined(PLATFORM_MSNT)
//     #include <windows.h>
//     char* read_symlink_windows(const char *path);
// #else
//     char* read_symlink(const char *path);
// #endif

#endif // UTILS_H