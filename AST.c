#include <stdio.h>
#include <stdlib.h>
#include "AST.h"
#include <string.h>




/* create an AST from a root value and two AST sons */
//this Ast concerne toutes les instruction : multiplication , addition , soustraction , logique .. toutes les oprations qui contiennent deux operateurs 
AST newBinaryAST(char *car, AST left, AST right)
{
  AST t=(struct _tree*) malloc(sizeof(struct _tree));
  if (t!=NULL){	/* malloc ok */
    t->car=car ;
    t->childs=left;
    t->next=right;
  } else 
  printf("MALLOC! ");
  return t;
}
/*  ast for the for looop*/
AST newForASt( char* car , AST expression1 , AST expression2, AST expression3 , AST COMMAND )
{
  AST t=(struct _tree*) malloc(sizeof(struct _tree));
  if (t!=NULL){	
    t->car=car ;
    t->childs=expression1;
    t->next=expression2;
    t->next->next=expression3;
  }
   return t;
  
}
/*Ast for the while loop and do while*/
AST newWhile(char* car , AST command )
{
     AST t=(struct _tree*) malloc(sizeof(struct _tree));
  if (t!=NULL){	
      t->car=car ;
      t->childs=command;
      t->next=NULL;
  }
    return NULL;
}
/* AST FOR IF ELSE */
AST ifelse(char * car , AST command1, AST command2)
{
   AST t=(struct _tree*) malloc(sizeof(struct _tree));
  if (t!=NULL){	
     t->car=car ;
     t->childs=command1;
      t->next=command2;
  }
   return t ;
}



/* cet AST conerne toutes les operation qui contiennent un opearateur ; la negation , auto incrementation */
AST newUnaryAST(char* car, AST son)
{
  return newBinaryAST(car, son, NULL);
}

/* create an AST leaf from a value */
AST newLeafAST(int val)
{
  AST t=(struct _tree*) malloc(sizeof(struct _tree));
  if (t!=NULL){	/* malloc ok */
    t->val=val;
    t->childs=NULL;
    t->next=NULL;
  } else printf("MALLOC! ");
  return t;
}

/* delete an AST */
void freeAST(AST t)
{
  if (t!=NULL) {
    //list
    while((t->next)!=NULL)
    {
        freeAST(t->next);
        t=t->next;
    }
   

    freeAST(t->childs);
    free(t);
  }
}

/* infix print an AST*/
//parcours en largeur (par niveau)
void printAST(AST t)
{
   if(t!=NULL)
   { 
     printf("arbre : %s,%d", (t->car),t->val);
     while(t->next !=NULL)
     {
       printf("car :%s val: %d",t->next->car,t->next->val);
     }
     printf("child: %s %d",t->childs->car,t->childs->val);
     
   }
}

