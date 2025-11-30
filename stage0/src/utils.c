#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include "pearl.h"
#include "utils.h"
#include "log.h"

void die(const char *message) {
    fprintf(stderr, "Fatal error: %s\n", message);
    exit(1);
}

#if defined(PLATFORM_WINDOWS)
#include <windows.h>
char* resolve_path(const char* path) {
    if (pearl_verbosity_level >= PEARL_VERBOSITY_DEBUG)
        pearl_log(LOG_INFO, msg_heap("Called Windows(MS-NT), path resolver.."));
    DWORD attrs = GetFileAttributesA(path);
    if (attrs == INVALID_FILE_ATTRIBUTES) {
        return NULL;
    }

    HANDLE h = CreateFileA(
        path,
        0,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS,
        NULL
    );

    if (h == INVALID_HANDLE_VALUE) {
        return NULL;
    }

    char buf[MAX_PATH];
    DWORD len = GetFinalPathNameByHandleA(
        h, buf, MAX_PATH, FILE_NAME_NORMALIZED
    );
    CloseHandle(h);

    if (len == 0 || len >= MAX_PATH) {
        return NULL;
    }

    char* out = _strdup(buf);
    if (strncmp(out, "\\\\?\\", 4) == 0) {
        memmove(out, out + 4, strlen(out) - 3);
    }
    return out;
}

#elif defined(PLATFORM_LINUX) || defined(PLATFORM_DARWIN)
#include <unistd.h>
#include <limits.h>
char* resolve_path(const char* path) {
    if (pearl_verbosity_level >= PEARL_VERBOSITY_DEBUG)
        pearl_log(LOG_INFO, msg_heap("Called Unix*, POSIX compliant path resolver.."));
    char* out = malloc(PATH_MAX);
    if (!out) return NULL;

    if (realpath(path, out) == NULL) {
        free(out);
        return NULL;
    }
    return out;
}
#else
// If You're using a POSSIX compatible system other than Linux or MacOS,
// you can implement resolve_path here like up(PLATFORM_LINUX and PLATFORM_DARWIN).
char* resolve_path(const char* path) {
    // Unsupported platform
    if (pearl_verbosity_level >= PEARL_VERBOSITY_DEBUG)
        pearl_log(LOG_ERROR, msg_heap("Called an function for a unsupported operation system family, if you're think this is mistake\n or you want to add your operating system family please open an issue: https://github.com/pearl-lang/pearl/issues"));
    return NULL;
}
#endif