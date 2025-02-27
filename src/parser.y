%{
  #include <stdio.h>
  int yylex (void);
  void yyerror (char const *);
%}

%token EOL
%token INTEGER
%token FLOAT
%token FUNCTION

%%
expr: EOL { printf("end of line: %d\n", $1); }
    ;
expr: INTEGER { printf("integer: %d\n", $1); }
    ;
expr: FLOAT { printf("bloat: %d\n", $1); }
    ;
expr: FUNCTION { printf("function: %d\n", $1); }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "pearl: error: %s\n", s);
}