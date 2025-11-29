#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "platform.h"
#include "vector.h"
#include "utils.h"
#include "pearl.h"
#include "cli.h"
#include "log.h"

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

    bool has_error = false;

    for( size_t i = 0; i < vector_size(&source_files); i++) {
        const char **src = (const char **)vector_get(&source_files, i);
        char *resolved_path = resolve_path(*src);
        if (resolved_path) {
            size_t len = strlen(resolved_path);
            if (len < 4) {
                has_error = true;
                if (pearl_verbosity_level >= PEARL_VERBOSITY_ERROR)
                    pearl_log(LOG_ERROR, msg_heap("Resolved path is too short: %s", resolved_path));
                free(resolved_path);
                continue;
            }

            if (strcmp(resolved_path + len - 4, ".prl") != 0) {
                has_error = true;
                fprintf(stderr, "The file \"%s\" is not a pearl(.prl) file.\n", resolved_path);
                if (pearl_verbosity_level >= PEARL_VERBOSITY_ERROR)
                    pearl_log(LOG_ERROR, msg_heap("Source file does not have .prl extension: %s", resolved_path));
                free(resolved_path);
                continue;
            }
        } else {
            has_error = true;
            if (pearl_verbosity_level >= PEARL_VERBOSITY_ERROR)
                pearl_log(LOG_ERROR, msg_heap("Failed to resolve path: %s", *src));
            continue;
        }

        free(resolved_path);
    }
    if (has_error) die("One or more errors occurred while resolving source file paths.");

    // Free resources
    vector_free(&source_files);

    return 0;
}