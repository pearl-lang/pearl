#include <stdio.h>
#include "platform.h"
#include "pearl.h"
#include "cli.h"
#include "log.h"

int main(int argc, char **argv) {
    pearl_config_t config = {
        .source_file = NULL,
        .output_file = NULL,
        .backend = BACKEND_LLVM
    };

    parse_args(argc, argv, &config);

    if(pearl_verbosity_level >= PEARL_VERBOSITY_INFO) {
        pearl_log(LOG_INFO, msg_heap("Output File: %s", config.output_file ? config.output_file : "Not specified"));
    }

    return 0;
}