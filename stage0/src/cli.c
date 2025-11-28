#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "platform.h"
#include "vector.h"
#include "pearl.h"
#include "cli.h"
#include "log.h"

void parse_args(int argc, char **argv, pearl_config_t *config) {
    if (argc <= 1) {
        printf("No arguments provided. Use -h or --help for usage information.\n");
        exit(1);
    }

    // NOTE: Short arguments can be combined like -vho output.pearl
    // But it doesn't designed for handle multiple parameters. If you want to use it with
    // multiple parameters, use long arguments like --output output.pearl --backend llvm
    // or one by one like -o output.pearl -b llvm. 
    for (int i = 1; i < argc; i++) {
        bool shift_i = false;

        if (argv[i][0] == '-' && (argv[i][1] != '\0' && argv[i][1] != '-')) {
            bool flag_handled = false;

            for (size_t j = 1; (argv[i][j] != '\0'); j++) {
                switch (argv[i][j]) {
                    case 'h':
                        short_help();
                        exit(0);
                        break; // Will not reach here.
                    case 'V':
                        printf("%s v%s - %s on %s\n", "Pearl", PEARL_VERSION, get_platform(), get_architecture());
                        exit(0);
                        break; // Will not reach here.
                    case 'o':
                        if (i + 1 < argc && argv[i + 1][0] != '-' && !flag_handled) {
                            config->output_file = argv[i + 1];
                            shift_i = true;
                            flag_handled = true;
                        } else {
                            printf("Pearl Error: \n");
                            printf("  -o requires a file name argument\n");
                            exit(1);
                        }
                        break;
                    case 'b':
                        if (i + 1 < argc && argv[i + 1][0] != '-' && !flag_handled) {
                            if (strcmp(argv[i + 1], "llvm") == 0) {
                                config->backend = BACKEND_LLVM;
                            } else if (strcmp(argv[i + 1], "pire") == 0) {
                                config->backend = BACKEND_PIRE;
                            } else {
                                if (pearl_verbosity_level >= PEARL_VERBOSITY_ERROR)
                                    pearl_log(LOG_ERROR, msg_heap("  Unknown backend: %s", argv[i + 1]));
                            }
                            shift_i = true;
                            flag_handled = true;
                        } else {
                            printf("Pearl Error: \n");
                            printf("  -b requires a backend type argument\n");
                            exit(1);
                        }
                        break;
                    case 'v':
                        if (j < strlen(argv[i])) {
                            pearl_set_verbosity();
                        }
                        break;
                    default:
                        if (pearl_verbosity_level >= PEARL_VERBOSITY_INFO)
                            pearl_log(LOG_WARNING, msg_heap("  Unknown option: %c", argv[i][j]));
                }
            }
            if (shift_i) i++; // increase i if we have consumed the next argument 
        } else if ((argv[i][0] == '-' && argv[i][1] == '-') && argv[i][2] != '\0') {
            if (strcmp(argv[i], "--help") == 0) {
                help();
                exit(0);
                break; // Will not reach here.
            } else if (strcmp(argv[i], "--version") == 0) {
                printf("Pearl Bootstrap Compiler\n");
                printf("Version:      %s\n", PEARL_VERSION);
                printf("Target:       %s\n", get_platform());
                printf("Architecture: %s\n", get_architecture());
                if (pearl_verbosity_level >= LOG_INFO) {
                    pearl_log(LOG_INFO, "Emitter configuration:");
                    switch(config->backend) {
                        case BACKEND_LLVM:
                            pearl_log(LOG_INFO, "  Backend: LLVM IR");
                            break;
                        case BACKEND_PIRE:
                            pearl_log(LOG_INFO, "  Backend: PIRE");
                            break;
                        default:
                            pearl_log(LOG_INFO, "  Backend: Unknown");
                    }
                }
                printf("Backend:      %s\n", config->backend == BACKEND_LLVM ? "LLVM" : "PIRE");

                exit(0);
                break; // Will not reach here.
            } else if (strcmp(argv[i], "--output") == 0) {
                if (i + 1 < argc && argv[i + 1][0] != '-') {
                    config->output_file = argv[i + 1];
                    i++; // Skip next argument as it's the output file
                } else {
                    printf("Pearl Error: \n");
                    printf("  --output requires a file name argument\n");
                    exit(1);
                }
            } else if (strcmp(argv[i], "--backend") == 0) {
                if (i + 1 < argc && argv[i + 1][0] != '-') {
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
                    printf("Pearl Error: \n");
                    printf("  --backend requires a backend type argument\n");
                    exit(1);
                }
            } else {
                if (pearl_verbosity_level >= PEARL_VERBOSITY_INFO)
                    pearl_log(LOG_WARNING, msg_heap("Unknown option: %s", argv[i]));
            }
        } else {
            if (pearl_verbosity_level >= PEARL_VERBOSITY_INFO)
                pearl_log(LOG_INFO, msg_heap("Positional argument: %s", argv[i]));
            const char *source_file = argv[i];
            if (!vector_push_back(config->source_file, &source_file)) {
                fprintf(stderr, "Failed to add source file to the list.");
                exit(1);
            }
        }
    }
}