%{
  #include <stdio.h>
  int yylex (void);
  void yyerror (char const *);
%}

%token EOL

%%
expr: EOL { printf("Resultat: %d\n", $1); }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "we got error sir: %s\n", s);
}