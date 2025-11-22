#include <stdio.h>
#include <stdlib.h>
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