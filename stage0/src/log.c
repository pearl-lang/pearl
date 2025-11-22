#include <stdio.h>
#include <stdlib.h>
#include "log.h"

void pearl_info(const char *message) {
    printf("(INFO): %s\n", message);
}

void pearl_error(const char *message) {
    fprintf(stderr, "(ERROR): %s\n", message);
}

void pearl_warning(const char *message) {
    printf("(WARNING): %s\n", message);
}