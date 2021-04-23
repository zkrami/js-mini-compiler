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
%token OR_OR
%token AND_AND 
%token DO
%token WHILE 
%token FOR 
%token UNDEFINED

%right AFFECTATION      
%left OR_OR AND_AND 
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
| IF '(' expression ')' command ELSE command
| IF '(' expression ')' command
| DO command WHILE '(' expression ')'   
| WHILE '(' expression ')' command 
| FOR '(' expression PT_VIRG expression PT_VIRG expression ')' command 
;

expression:
expression '+' expression
| expression '-' expression
| expression '*' expression
| expression '/' expression
| expression  OR_OR expression
| expression  AND_AND expression
| expression  EGALE_EGALE expression
| expression  PAS_EGALE expression
| expression  INF expression
| expression  SUP expression
| expression  SUP_EGAL expression
| expression  INF_EGAL expression
| '(' expression ')' 
|  VARIABLE AFFECTATION expression 
| '-' expression %prec MOINSU
| NEGATION  expression
| INCREMENTATION VARIABLE
| DECREMENTATION VARIABLE
|  VARIABLE INCREMENTATION
|  VARIABLE DECREMENTATION
| NOMBRE
| BOOL
| VARIABLE
| UNDEFINED





;
%%

#include <stdio.h> 
int yyerror(const char *msg){ printf("Parsing:: syntax error\n"); puts(msg); return 1;}
int yywrap(void){ return 1; } /* stop reading flux yyin */
