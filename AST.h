#ifndef _AST_H_
#define _AST_H_

/* unary-and-binary tree structure */
struct _tree {
  char* car;           
  int boolean_value;
  char* var_name; 
  double number_value; 
  struct _tree* childs;    	
  struct _tree* next;  
};

typedef struct _tree* AST;

AST newQuaternaryAST(char *car, AST node1, AST node2 , AST node3 , AST node4);

AST newTernaryAST(char *car, AST node1, AST node2 , AST node3 ); 

/* create an AST from a root value and one AST son */
AST newUnaryAST(char* car, AST son);

/* create an AST from a root value and two AST sons */
AST newBinaryAST(char* car, AST left, AST right);

/* create an AST leaf from a number */
AST newNumberLeafAST(double val);

/* create an AST leaf from a boolean 0 for false 1 for true  */
AST newBooleanLeafAST(int val);

/* create an AST leaf from a variable */
AST newVariableLeafAST(char* val);

/* create an AST leaf from a constant (undefined , null , Infinity , Nan) */
AST newConstantLeafAST(char* val);

/* delete an AST */
void freeAST(AST t);

/* print an AST*/
void printAST(AST t);

#endif // !_AST_H_
