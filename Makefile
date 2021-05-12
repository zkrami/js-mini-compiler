CFLAGS = -g -Wall
CPPFLAGS = -g -Wall
YACC = bison -d 
CC = gcc
CSRCS = AST.c parseur.tab.c lex.yy.c
CPPSRC = compiler.cpp main.cpp
OBJS = $(CSRCS:.c=.o)  $(CPPSRC:.cpp=.o) 

all: compiler 

clean:
	rm -f compiler parseur *.tab.c *.tab.h lex.yy.c *.yy.c *.o 



grammer:
	$(YACC) parseur.y

lexer: grammer
	flex lexeur.l 


parseur: lexer
	 gcc $(CFLAGS) -o parseur  main.c AST.c parseur.tab.c lex.yy.c

parseur.tab.o: 	
	gcc $(CFLAGS) -c parseur.tab.c -o parseur.tab.o

lex.yy.o: 	
	gcc $(CFLAGS) -c lex.yy.c -o lex.yy.o

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@


%.o : %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

compiler:lexer $(OBJS)
	g++ $(CPPFLAGS)  -o compiler $(OBJS)
	 
