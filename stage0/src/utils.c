#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include "utils.h"

void die(const char *message) {
    fprintf(stderr, "Fatal error: %s\n", message);
    exit(1);
}

// #if defined(PLATFORM_LINUX) || defined(PLATFORM_DARWIN)
//     #include <unistd.h>
//     char* read_symlink_unix(const char *path) {
//         ssize_t len = 0;
//         char *buf = malloc(1024);
//         if (!buf) {
//             return NULL;
//         }
//         len = readlink(path, buf, 1024 - 1);
//         if (len == -1) {
//             free(buf);
//             return NULL;
//         }
//         buf[len] = '\0';
//         return buf;
//     }
// #elif defined(PLATFORM_MSNT)
//     #include <windows.h>
//     char* read_symlink_windows(const char *path) {
//         char buf[MAX_PATH];
//         DWORD len = GetFinalPathNameByHandleA((HANDLE)path, buf, MAX_PATH, FILE_NAME_NORMALIZED);
//         if (len == 0 || len >= MAX_PATH) {
//             return NULL;
//         }

//         char *result = malloc(len + 1);
//         if (!result) {
//             return NULL;
//         }
//         memcpy(result, buf, len);
//         result[len] = '\0';
//         return result;
//     }
// #else
//     char* read_symlink(const char *path) {
//         return NULL; // Unsupported platform
//     }
// #endif