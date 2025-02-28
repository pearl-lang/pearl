%{
    #include <stdbool.h>
    #include "parser.h"
%}

%%
[ \t\n\r]+   ;  // Whitespace karakterlerini yoksay
"fonk"  { return FUNCTION; }
"{"     { return SCOPEON; }
"}"     { return SCOPEOFF; }
"\""    { return QUOTE; }
"("     { return LBRACKET; }
")"     { return RBRACKET; }
[0-9]+  { return INTEGER; }
\n      { return EOL; }
\"([^\"]*)\" { return STRING; }
[[:digit:]]*(\.[[:digit:]]+)? { return FLOAT; }
.       { }
%%

void lexline(char *input) {
    YY_BUFFER_STATE buf = yy_scan_string(input);
    yyparse();
    yy_delete_buffer(buf);
}

int yywrap() {
    return true;
}

/* 
    - Integer and float not yet completed need to rewrite.
*/