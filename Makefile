CFLAGS = -g -Wall
YACC = bison -d 

all:  compiler 

clean:
	rm -f parseur *.tab.c *.tab.h lex.yy.c *.yy.c



grammer:
	$(YACC) parseur.y

lexer: grammer
	flex lexeur.l 


parseur: lexer
	 gcc $(CFLAGS) -o parseur  main.c AST.c parseur.tab.c lex.yy.c

compiler: lexer
	gcc $(CFLAGS) -o compiler  main.c AST.c parseur.tab.c lex.yy.c compiler.c