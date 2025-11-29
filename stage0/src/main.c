#include <stdio.h>
#include "platform.h"
#include "pearl.h"
#include "cli.h"
#include "log.h"
#include "vector.h"

int main(int argc, char **argv) {
    // Source files vector
    vector_t source_files;
    vector_init(&source_files, sizeof(const char*));

    // Pearl configuration
    pearl_config_t config = {
        .source_file = &source_files,
        .output_file = NULL,
        .backend     = BACKEND_LLVM
    };

    // Parse command line arguments
    parse_args(argc, argv, &config);

    if(pearl_verbosity_level >= PEARL_VERBOSITY_INFO) {
        pearl_log(LOG_INFO, msg_heap("Parsed %zu source files.", vector_size(&source_files)));
        for (size_t i = 0; i < vector_size(&source_files); i++) {
            const char **src = (const char **)vector_get(&source_files, i);
            pearl_log(LOG_INFO, msg_heap("  Source File %zu: %s", i + 1, *src));
        }
        pearl_log(LOG_INFO, msg_heap("Output File: %s", config.output_file ? config.output_file : "Not specified"));
        pearl_log(LOG_INFO, msg_heap("Backend: %s", config.backend == BACKEND_LLVM ? "LLVM" : "PIRE"));
    }

    // Free resources
    vector_free(&source_files);

    return 0;
}