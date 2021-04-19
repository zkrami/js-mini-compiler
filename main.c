/* file main.c :: limited to yyparse() call and printed result */
/* compilation: gcc -o main main.c parseur.tab.c lex.yy.c */
/* result: main = syntaxic analysis */
/* usage: ./main < input.txt */
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
    }
    if (yyparse() == 0)
    {                                      /* yyparse calls yylex */
        printf("\nParsing:: syntax OK\n"); /* reached if parsing folllows the grammar */
    }
    exit(EXIT_SUCCESS);
}
