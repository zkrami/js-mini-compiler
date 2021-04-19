/* file parseur.y */
/* compilation: bison -d parseur.y */
/* result: parseur.tab.c = C code for syntaxic analyser */
/* result: parseur.tab.h = def. of lexical units aka lexems */
%{
    int yylex(void); /* -Wall : avoid implicit call */
    int yyerror(const char*); /* same for bison */
%}
%token NOMBRE
%token PT_VIRG
%start resultat /* axiom */

%%
resultat: programme ;
programme:
expression PT_VIRG programme
| ''


expression:
expression '+' terme
| expression '-' terme
| terme
;

terme:
terme '*' facteur
| facteur
;

facteur:
| '(' expression ')'
| '-' facteur
| NOMBRE
;
%%

#include <stdio.h> 
int yyerror(const char *msg){ printf("Parsing:: syntax error\n"); puts(msg); return 1;}
int yywrap(void){ return 1; } /* stop reading flux yyin */
