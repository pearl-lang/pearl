#include <stdio.h>
#include <stdlib.h>

void die(const char *message) {
    fprintf(stderr, "Fatal error: %s\n", message);
    exit(1);
}