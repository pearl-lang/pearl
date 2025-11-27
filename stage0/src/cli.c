#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "platform.h"
#include "pearl.h"
#include "cli.h"
#include "log.h"

void parse_args(int argc, char **argv, pearl_config_t *config) {
    if (argc <= 1) {
        printf("~> No arguments provided. Use -h or --help for usage information.\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && (argv[i][1] != '\0' && argv[i][1] != '-')) {
            for (size_t j = 1; argv[i][j] != '\0'; j++) {
                switch (argv[i][j]) {
                    case 'h':
                        short_help();
                        exit(0);
                        break; // Will not reach here.
                    case 'V':
                        printf("%s\n", PEARL_VERSION);
                        exit(0);
                        break; // Will not reach here.
                    case 'v':
                        if (j < strlen(argv[i])) {
                            pearl_set_verbosity();
                        }
                        break;
                    default:
                        pearl_log(LOG_WARNING, msg_heap("  Unknown option: %c", argv[i][j]));
                }
            }
        } else if ((argv[i][0] == '-' && argv[i][1] == '-') && argv[i][2] != '\0') {
            if (strcmp(argv[i], "--help") == 0) {
                help();
                exit(0);
                break; // Will not reach here.
            } else if (strcmp(argv[i], "--version") == 0) {
                printf("%s v%s - %s on %s\n", "Pearl", PEARL_VERSION, get_platform(), get_architecture());
                exit(0);
                break; // Will not reach here.
            } else if (strcmp(argv[i], "--output") == 0) {
                if (i + 1 < argc) {
                    config->output_file = argv[i + 1];
                    i++; // Skip next argument as it's the output file
                } else {
                    if (pearl_verbosity_level >= PEARL_VERBOSITY_ERROR)
                        pearl_log(LOG_ERROR, msg_heap("  --output requires a file name argument"));
                }
            } else if (strcmp(argv[i], "--backend") == 0) {
                if (i + 1 < argc) {
                    if (strcmp(argv[i + 1], "llvm") == 0) {
                        config->backend = BACKEND_LLVM;
                    } else if (strcmp(argv[i + 1], "pire") == 0) {
                        config->backend = BACKEND_PIRE;
                    } else {
                        if (pearl_verbosity_level >= PEARL_VERBOSITY_ERROR)
                            pearl_log(LOG_ERROR, msg_heap("  Unknown backend: %s", argv[i + 1]));
                    }
                    i++; // Skip next argument as it's the backend type
                } else {
                    if (pearl_verbosity_level >= PEARL_VERBOSITY_ERROR)
                        pearl_log(LOG_ERROR, msg_heap("  --backend requires a backend type argument"));
                }
            } else {
                if (pearl_verbosity_level >= PEARL_VERBOSITY_INFO)
                    pearl_log(LOG_WARNING, msg_heap("Unknown option: %s", argv[i]));
            }
        } else {
            if (pearl_verbosity_level >= PEARL_VERBOSITY_INFO)
                pearl_log(LOG_INFO, msg_heap("Positional argument: %s", argv[i]));
        }
    }
}