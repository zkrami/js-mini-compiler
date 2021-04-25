#ifndef _AST_H_
#define _AST_H_

/* unary-and-binary tree structure */
struct _tree {
  char* car;                    	/* char for arithmetic operation */
  int val;			/* int  for value */
  struct _tree* childs;    	/* used for unary node but NULL if leaf */
  struct _tree* next;   	/* NULL if unary node or leaf*/
};

typedef struct _tree* AST;

/* create an AST from a root value and two AST sons */
AST newBinaryAST(char* car, AST left, AST right);

/* create an AST from a root value and one AST son */
AST newUnaryAST(char* car, AST son);

/* create an AST leaf from a value */
AST newLeafAST(int val);
/* create an AST leaf from a value */
AST newthirdelyAST(int val);
/* delete an AST */
void freeAST(AST t);

/* print an AST*/
void printAST(AST t);

AST newForASt( char* car , AST expression1 , AST expression2, AST expression3 , AST COMMAND );

AST newWhile(char* car , AST command );

AST ifelse(char * car , AST command1, AST command2);
#endif // !_AST_H_
