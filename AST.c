#include <stdio.h>
#include <stdlib.h>
#include "AST.h"
#include <string.h>



/* cet AST conerne toutes les operation qui contiennent un opearateur ; la negation , auto incrementation */
AST newUnaryAST(char* car, AST son)
{
   AST t=(struct _tree*) malloc(sizeof(struct _tree));
    if (t!=NULL){	
        t->car=car ;
        t->childs=son;
    }
   return t ;

}

/* create an AST from a root value and two AST sons */
//this Ast concerne toutes les instruction : multiplication , addition , soustraction , logique .. toutes les oprations qui contiennent deux operateurs 
AST newBinaryAST(char *car, AST left, AST right)
{
  AST t=(struct _tree*) malloc(sizeof(struct _tree));
  if (t!=NULL){
    t->car=car ;
    t->childs=left;
    t->childs->next = right;
  } 
  
  return t;
}

AST newTernaryAST(char *car, AST node1, AST node2 , AST node3 )
{
  AST t=(struct _tree*) malloc(sizeof(struct _tree));
  if (t!=NULL){
    t->car=car ;
    t->childs=node1;
    node1->next=node2;
    node2->next=node3;
  }  
  
  return t;
}


AST newQuaternaryAST(char *car, AST node1, AST node2 , AST node3 , AST node4)
{
  AST t=(struct _tree*) malloc(sizeof(struct _tree));
  if (t!=NULL){
    t->car=car ;
    t->childs=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
  }  
  return t;
}




void freeAST(AST t)
{
  if (t!=NULL) {
    //list
    AST c = t->childs; 
    while(c!=NULL)
    {
        freeAST(c);
        c=c->next;
    }
       
    free(t);
  }
}


void printAST(AST t)
{

   if(t!=NULL)
   { 
     printf(" %s ", t->car);
     AST c = t->childs; 
     while(c !=NULL)
     {
       printAST(c); 
       c = c->next; 
     }          
   }
}


AST newNumberLeafAST(double val){
  AST t=(struct _tree*) malloc(sizeof(struct _tree));  
  if (t!=NULL){	
    t->car = "number"; 
    t->number_value=val;    
  } 
  return t; 
  
}


AST newBooleanLeafAST(int val){
  AST t=(struct _tree*) malloc(sizeof(struct _tree));  
  if (t!=NULL){	
    t->car = "bool"; 
    t->boolean_value=val;    
  } 
  return t; 
  
}

/* create an AST leaf from a variable */
AST newVariableLeafAST(char* val){
  AST t=(struct _tree*) malloc(sizeof(struct _tree));  
  if (t!=NULL){	
    t->car = "var"; 
    t->str_value=val;    
  } 
  return t; 
  
}

AST newConstantLeafAST(char* val){
  AST t=(struct _tree*) malloc(sizeof(struct _tree));  
  if (t!=NULL){	
    t->car = "constant"; 
    t->str_value=val;    
  } 
  return t; 
  
}

