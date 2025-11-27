#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "platform.h"
#include "pearl.h"
#include "cli.h"
#include "log.h"

void parse_args(int argc, char **argv) {
    if (argc <= 1) {
        pearl_log(LOG_ERROR, "No arguments provided.");
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
            bool has_value = false;

            if (strcmp(argv[i], "--help") == 0) {
                help();
                exit(0);
                break; // Will not reach here.
            } else if (strcmp(argv[i], "--version") == 0) {
                printf("%s v%s - %s on %s\n", "Pearl", PEARL_VERSION, get_platform(), get_architecture());
                exit(0);
                break; // Will not reach here.
            }

            if (has_value) {
                while (i + 1 < argc && argv[i + 1][0] != '-') {
                    pearl_log(LOG_INFO, msg_heap("  Option Value: %s", argv[i + 1]));
                    i++;
                }
            }
        } else {
            pearl_log(LOG_INFO, msg_heap("Positional argument: %s", argv[i]));
        }
    }
}