#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include "utils.h"

void die(const char *message) {
    fprintf(stderr, "Fatal error: %s\n", message);
    exit(1);
}