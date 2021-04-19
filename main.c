/* file main.c :: limited to yyparse() call and printed result */
/* compilation: gcc -o main main.c parseur.tab.c lex.yy.c */
/* result: main = syntaxic analysis */
/* usage: ./main < input.txt */
#include <stdio.h> 
#include <stdlib.h> 
int main(void)
{
    if (yyparse() == 0)
    {                                      /* yyparse calls yylex */
        printf("\nParsing:: syntax OK\n"); /* reached if parsing folllows the grammar */
    }
    exit(EXIT_SUCCESS);
}

