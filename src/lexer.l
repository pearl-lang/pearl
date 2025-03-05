%{
    #include <stdbool.h>
    #include "parser.h"
%}

%%
[ \t\n\r]+   ;
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

int yywrap() {
    return true;
}

/* 
    - Integer and float not yet completed need to rewrite.
*/