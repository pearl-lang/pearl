%{
#include <stdio.h>
int word_count = 0;
int number_count = 0;
%}

%%
[0-9]+   { number_count++; }
[a-zA-Z]+ { word_count++; }
\n       {}
.        {}
%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Can't open the file.");
            return 1;
        }
        yyin = file;
    }

    yylex();
    printf("Word count: %d\n", word_count);
    printf("Number count: %d\n", number_count);
    return 0;
}

int yywrap() {
    return 1;
}
