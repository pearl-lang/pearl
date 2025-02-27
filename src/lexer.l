%{
    #include <stdbool.h>
    #include "parser.h"
%}

%%
"fonk" { return FUNCTION; }
[0-9]+ { return INTEGER; }
[[:digit:]]*(\.[[:digit:]]+)?  { return FLOAT; }
\n  { return EOL; }
. { return false; }
%%

void lexin(char *input) {
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