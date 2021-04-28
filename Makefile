CFLAGS = -g -Wall
YACC = bison -d 

all:  parseur 

clean:
	rm -f parseur *.tab.c *.tab.h lex.yy.c *.yy.c

grammer:
	$(YACC) -d parseur.y

lexer: grammer
	flex lexeur.l 


parseur: lexer
	 gcc $(CFLAGS) -o parseur main.c parseur.tab.c lex.yy.c

