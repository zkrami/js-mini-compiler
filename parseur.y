/* file parseur.y */
/* compilation: bison -d parseur.y */
/* result: parseur.tab.c = C code for syntaxic analyser */
/* result: parseur.tab.h = def. of lexical units aka lexems */
%{
    int yylex(void); /* -Wall : avoid implicit call */
    int yyerror(const char*); /* same for bison */
  
%}
%token VARIABLE
%token NOMBRE
%token PT_VIRG
%token BOOL
%token EGALE_EGALE
%token PAS_EGALE
%token INF
%token INF_EGAL
%token SUP
%token SUP_EGAL
%token NEGATION
%token AFFECTATION
%token INCREMENTATION
%token DECREMENTATION
%token IF 
%token ELSE
%left EGALE_EGALE PAS_EGALE
%left  INF INF_EGAL SUP SUP_EGAL


%left '+' '-'
%left '*' '/'

%nonassoc MOINSU            
%nonassoc NEGATION

%start programme /* axiom */
%%


programme:
command
|
command programme
;

command:
expression PT_VIRG 
| PT_VIRG
| '{' programme '}'
| affectation PT_VIRG
| IF '(' expression ')' command ELSE command
| IF '(' expression ')' command
;

affectation:
VARIABLE AFFECTATION expression
;

expression:
expression '+' expression
| expression '-' expression
| expression '*' expression
| expression '/' expression
| expression  EGALE_EGALE expression
| expression  PAS_EGALE expression
| expression  INF expression
| expression  SUP expression
| expression  SUP_EGAL expression
| expression  INF_EGAL expression
| '(' expression ')'
| '-' expression %prec MOINSU
| NEGATION  expression
| INCREMENTATION VARIABLE
| DECREMENTATION VARIABLE
|  VARIABLE INCREMENTATION
|  VARIABLE DECREMENTATION
| NOMBRE
| BOOL
| VARIABLE





;
%%

#include <stdio.h> 
int yyerror(const char *msg){ printf("Parsing:: syntax error\n"); puts(msg); return 1;}
int yywrap(void){ return 1; } /* stop reading flux yyin */
