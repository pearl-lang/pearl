#include <stdio.h>
#include <stdlib.h>
#include "cli.h"
#include "log.h"

void parse_args(int argc, char **argv) {
    if (argc <= 1) {
        pearl_log(LOG_ERROR, "No arguments provided.");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        // For now, just print the arguments
        printf("Arg %d: %s\n", i, argv[i]);
    }
}