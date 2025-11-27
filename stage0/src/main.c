#include <stdio.h>
#include "platform.h"
#include "pearl.h"
#include "cli.h"

int main(int argc, char **argv) {
    pearl_config_t config = {
        .source_file = NULL,
        .output_file = NULL,
        .backend = BACKEND_LLVM
    };

    parse_args(argc, argv, &config);

    printf("Output File: %s\n", config.output_file ? config.output_file : "Not specified");

    return 0;
}