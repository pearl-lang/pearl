#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "log.h"

void pearl_log(int level, const char *message) {
    const char *level_str;
    switch (level) {
        case LOG_INFO:
            level_str = "INFO";
            break;
        case LOG_WARNING:
            level_str = "WARNING";
            break;
        case LOG_ERROR:
            level_str = "ERROR";
            break;
        default:
            level_str = "UNKNOWN";
    }
    printf("(%s): %s\n", level_str, message);
}

char* msg_heap(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    if (len < 0) {
        return NULL;
    }

    char *buffer = (char *)malloc(len + 1);
    if (!buffer) {
        return NULL;
    }

    va_start(args, fmt);
    vsnprintf(buffer, len + 1, fmt, args);
    va_end(args);

    return buffer;
}