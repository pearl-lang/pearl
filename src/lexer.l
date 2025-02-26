%{
    #include "parser.h" 
%}

%%
\n  { return EOL; }
%%

int yywrap() {
    return 1;
}