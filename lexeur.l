%{
#include <stdio.h> /* printf */
#include "parseur.tab.h" /* token constants def. in parseur.y via #define */
%}
%%
((([0-9]+(\.[0-9]*)?)|(\.[0-9]+))(e-?[0-9]+)?)|NaN|Infinity { printf("lex::NOMBRE %s\n",yytext); return NOMBRE; }
;  { printf("lex::PT_VIRG %s\n", yytext); return PT_VIRG; }
"="     { printf("lex:: afectation %s\n", yytext); return AFFECTATION; } 
true|false { printf("lex:: boolean %s\n", yytext); return BOOL; }
"=="   { printf("lex:: egale %s\n", yytext); return EGALE_EGALE; }
"!="   { printf("lex:: egale %s\n", yytext); return PAS_EGALE; }
"!"   { printf("lex:: egale %s\n", yytext); return NEGATION; }
"<" { printf("lex:: operateur relation  %s\n", yytext); return INF; }
">"  { printf("lex:: operateur relation  %s\n", yytext); return SUP; }
">="  { printf("lex:: operateur relation  %s\n", yytext); return SUP_EGAL; }
"<="  { printf("lex:: operateur relation  %s\n", yytext); return INF_EGAL; }
"&&" { { printf("lex:: operateur relation  %s\n", yytext); return AND_AND; } }
"||" { printf("lex:: operateur relation  %s\n", yytext); return OR_OR; }
if  { printf("lex::  if  %s\n", yytext); return  IF; }
else  { printf("lex::  else  %s\n", yytext); return  ELSE; }
do  { printf("lex::  do  %s\n", yytext); return  DO; }
while  { printf("lex::  do  %s\n", yytext); return  WHILE; }
[a-z][a-zA-Z_]* { printf("lex:: variable %s\n", yytext); return VARIABLE; }
"++" { printf("lex::  incrementation %s\n", yytext); return  INCREMENTATION; }
"--" { printf("lex::  decrementation %s\n", yytext); return  DECREMENTATION; }
\/\*([^*]|\*+[^/])*\*+\/ { printf("lex:: bloc commentaire %s\n", yytext);  }
\/\/.* { printf("lex:: linge commentaire %s\n", yytext);  }
[ \t\n] { ; } /* ignore space, tab, and line return */
. { printf("lex::char %s\n",yytext); return yytext[0]; } /* other one-char = token, ex. '+' */

%%
