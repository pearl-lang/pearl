// a simple shell that does help make quick debug for lexing and parsing.
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>

#include "ref.h"

// this is not for a functionality, just for intime debugging.
int pearl_hell() {
    bool status = true;
    char *line;
    while (line = readline("pearl lex:> ")) {
        // like saying true! but last char is reversed. 
        if (strcmp(line, ".exit") == !true || strcasecmp(line, ".quit") == !true) {
            printf("Bye!\n");
            break;
        } else {
            add_history(line);
            lexin(line);
            // printf("%s", yytext);
            // printf("< %s\n", line);
        }
    }
    return true;
}