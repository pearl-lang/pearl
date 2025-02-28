%{
  #include <stdio.h>
  int yylex (void);
  void yyerror (char const *);
%}

%token EOL
%token INTEGER
%token FLOAT
%token FUNCTION
%token SCOPEON
%token SCOPEOFF
%token QUOTE
%token LBRACKET
%token RBRACKET
%token STRING

%%
program: FUNCTION STRING { printf("function called\n"); }
%%

void yyerror(const char *s) {
    fprintf(stderr, "pearl: error: %s\n", s);
}