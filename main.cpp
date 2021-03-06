/* file main.c :: limited to yyparse() call and printed result */
/* compilation: gcc -o main main.c parseur.tab.c lex.yy.c */
/* result: main = syntaxic analysis */
/* usage: ./main < input.txt */
#include <stdio.h>
#include <stdlib.h>

#include "compiler.hpp"
extern FILE *yyin;

extern "C" int yyparse(AST* pt);


int main(int argc, char **argv)
{
    AST result = NULL ; 
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
    }
    if (yyparse(&result) == 0)
    {                  
        printf("\nParsing:: syntax OK\n");     
        compile(result); 
        freeAST(result); 
    }
    exit(EXIT_SUCCESS);
}
