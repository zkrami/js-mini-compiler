/* file parseur.y */
/* compilation: bison -d parseur.y */
/* result: parseur.tab.c = C code for syntaxic analyser */
/* result: parseur.tab.h = def. of lexical units aka lexems */
%{
    #include "AST.h" 
    int yylex(void); /* -Wall : avoid implicit call */
    int yyerror(AST* pt, const char*); /* same for bison */
    #define NULL 0
%}
%parse-param {AST* pt}
%union {
    AST node;
    double number;
};
%type <node> programme  command identifiant expression decl_args arguements


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
%token FUNCTION
%token UNDEFINED
%token RETURN

%right AFFECTATION      
%left OR_OR AND_AND 
%left EGALE_EGALE PAS_EGALE
%left  INF INF_EGAL SUP SUP_EGAL
%left '+' '-'
%left '*' '/'

%nonassoc MOINSU            
%nonassoc NEGATION

 
%%

resultat: programme { *pt = newUnaryAST("main" , $1 ) ;  }  /* axiom */


programme:
command { $$= newUnaryAST("programme" , $1 ) ;  } 
| command programme { $$= newBinaryAST("programme" , $1 ,  $2) ;  } 
;

command:
expression PT_VIRG { $$= newUnaryAST("command" , $1);  } 
| PT_VIRG  { $$= newUnaryAST(";" , NULL ) ;  } 
| '{' programme '}' { $$= newUnaryAST("command" , $2 ) ;  } 
| IF '(' expression ')' command ELSE command  { $$= newTernaryAST("if_else" , $3 , $5 , $7 ) ;  } 
| IF '(' expression ')' command   { $$ = newBinaryAST("if" , $3 , $5); }
| DO command WHILE '(' expression ')'    { $$ = newBinaryAST("do_while" , $2 , $5); }
| WHILE '(' expression ')' command { $$ = newBinaryAST("while" , $3 , $5); }
| FOR '(' expression PT_VIRG expression PT_VIRG expression ')' command  { $$ = newQuaternaryAST("for" , $3 , $5 , $7 , $9 ); }
| FUNCTION identifiant '(' decl_args ')' '{' programme '}'  { $$ = newTernaryAST("function" , $2 , $4 , $7 ); }
| RETURN expression PT_VIRG  { $$ = newUnaryAST("return" , $2 ); }
;
decl_args: 
 %empty { $$ = newUnaryAST("decl_args" , NULL ); }
| identifiant { $$ = newBinaryAST("decl_args" , $1 , NULL); }
| identifiant ',' decl_args  { $$ = newBinaryAST("decl_args" , $1 , $3); };

arguements: 
 %empty  { $$ = newUnaryAST("arguements" , NULL ); }
| expression  { $$ = newBinaryAST("arguements" , $1 , NULL); }
| expression ',' arguements   { $$ = newBinaryAST("arguements" , $1 , $3); } 

identifiant: VARIABLE { $$ = newConstantLeafAST("");  }

expression:
expression '+' expression { $$ = newBinaryAST("+" , $1 , $3); }
| expression '-' expression { $$ = newBinaryAST("-" , $1 , $3); }
| expression '*' expression { $$ = newBinaryAST("*" , $1 , $3); }
| expression '/' expression { $$ = newBinaryAST("/" , $1 , $3); }
| expression  OR_OR expression { $$ = newBinaryAST("||" , $1 , $3); }
| expression  AND_AND expression { $$ = newBinaryAST("&&" , $1 , $3); }
| expression  EGALE_EGALE expression { $$ = newBinaryAST("==" , $1 , $3); }
| expression  PAS_EGALE expression { $$ = newBinaryAST("!=" , $1 , $3); }
| expression  INF expression { $$ = newBinaryAST("<" , $1 , $3); }
| expression  SUP expression { $$ = newBinaryAST(">" , $1 , $3); }
| expression  SUP_EGAL expression { $$ = newBinaryAST(">=" , $1 , $3); }
| expression  INF_EGAL expression { $$ = newBinaryAST("<=" , $1 , $3); }
| '(' expression ')'  { $$ = newUnaryAST("()" , $2 ); }
|  identifiant AFFECTATION expression { $$ = newBinaryAST("=" , $1 , $3 ); }
| '-' expression %prec MOINSU { $$ = newUnaryAST("u-" , $2 ); }
| NEGATION  expression { $$ = newUnaryAST("!" , $2 ); }
| INCREMENTATION identifiant { $$ = newUnaryAST("++x" , $2 ); }
| DECREMENTATION identifiant { $$ = newUnaryAST("--x" , $2 ); }
|  identifiant INCREMENTATION { $$ = newUnaryAST("x++" , $1 ); }
|  identifiant DECREMENTATION { $$ = newUnaryAST("x--" , $1 ); }
| identifiant '('arguements')' { $$ = newBinaryAST("call" , $1 , $3 ); }
| NOMBRE { $$ = newNumberLeafAST(0);  }
| BOOL { $$ = newBooleanLeafAST(0);  }
| identifiant { $$ = $1; }
| UNDEFINED  { $$ = newConstantLeafAST("undefined");  }





;
%%

#include <stdio.h> 
int yyerror(AST* pt, const char *msg){ printf("Parsing:: syntax error\n"); puts(msg); return 1;}
int yywrap(void){ return 1; } /* stop reading flux yyin */
