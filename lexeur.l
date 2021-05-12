%{
#include <stdio.h> /* printf */
#include "AST.h" 
#include "parseur.tab.h" /* token constants def. in parseur.y via #define */
#include <string.h>
#include <stdio.h>

double parseNumber(const char *st){
    double d; 
    sscanf(st, "%lf", &d);
    return d; 
}

int parseBool(const char* st){
    
    return strcmp(st , "true") == 0 ? 1 : 0; 
}

%}
%%
NaN|Infinity|undefined  {printf("lex::Constant %s\n",yytext); yylval.str = yytext;  return CONSTANT; }
((([0-9]+(\.[0-9]*)?)|(\.[0-9]+))(e-?[0-9]+)?) { yylval.number = parseNumber(yytext);   printf("lex::NOMBRE %s\n",yytext); return NOMBRE; }
;  { printf("lex::PT_VIRG %s\n", yytext); return PT_VIRG; }
"="     { printf("lex::afectation %s\n", yytext); return AFFECTATION; } 
true|false { printf("lex::boolean %s\n", yytext); yylval.boolean = parseBool(yytext);  return BOOL; }
"=="   { printf("lex::egale %s\n", yytext); return EGALE_EGALE; }
"!="   { printf("lex::egale %s\n", yytext); return PAS_EGALE; }
"!"   { printf("lex::egale %s\n", yytext); return NEGATION; }
"<" { printf("lex::operateur relation  %s\n", yytext); return INF; }
">"  { printf("lex::operateur relation  %s\n", yytext); return SUP; }
">="  { printf("lex::operateur relation  %s\n", yytext); return SUP_EGAL; }
"<="  { printf("lex::operateur relation  %s\n", yytext); return INF_EGAL; }
"&&" { { printf("lex::operateur relation  %s\n", yytext); return AND_AND; } }
"||" { printf("lex::operateur relation  %s\n", yytext); return OR_OR; }
if  { printf("lex::if  %s\n", yytext); return  IF; }
else  { printf("lex::else  %s\n", yytext); return  ELSE; }
do  { printf("lex::do  %s\n", yytext); return  DO; }
while  { printf("lex::while  %s\n", yytext); return  WHILE; }
for  { printf("lex::for  %s\n", yytext); return  FOR; }
function { printf("lex::function  %s\n", yytext); return  FUNCTION; }
return { printf("lex::return  %s\n", yytext); return  RETURN; }
[a-zA-Z_]+ { printf("lex::variable %s\n", yytext); yylval.str = yytext;   return VARIABLE; }
"++" { printf("lex::incrementation %s\n", yytext); return  INCREMENTATION; }
"--" { printf("lex::decrementation %s\n", yytext); return  DECREMENTATION; }
\/\*([^*]|\*+[^/])*\*+\/ { printf("lex::bloc commentaire %s\n", yytext);  }
\/\/.* { printf("lex::linge commentaire %s\n", yytext);  }
[ \t\n\r] { ; } /* ignore space, tab, and line return */
. { printf("lex::char %s\n",yytext); return yytext[0]; } /* other one-char = token, ex. '+' */

%%
