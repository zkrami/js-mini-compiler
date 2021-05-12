#ifndef _COMPILER_H_
#define _COMPILER_H_
#include "AST.h"
#include <string.h>
#include <stdio.h>
int is(const char* s, const char* type){
    return !strcmp(s,type); 
}
void compile(AST ast){



}
int generate(AST ast , FILE* out)
{
    
    
    /*
    main  programme command if if_else do_while while for function return   decl_args arguements
    + - * / || && == != < > >= <= () = u- ! ++x --x  x++ x-- call number bool var constant
 */
    const char* current = ast->car;
    if(is(current , "main")){

    }else if(is(current,"programme")){

    }else if(is(current, "command")){

    }else if(is(current, "if")){
        
    }else if(is(current, "if_else")){
        
    }else if(is(current, "do_while")){
        
    }else if(is(current, "while")){
        
    }else if(is(current, "for")){
        
    }else if(is(current, "function")){
        
    }else if(is(current, "return")){
        
    }else if(is(current, "+")){
        
    }else if(is(current, "-")){
        
    }else if(is(current, "*")){
        
    }else if(is(current, "/")){
        
    }else if(is(current, "||")){
        
    }else if(is(current, "&&")){
    }else if(is(current, "==")){
        
    }else if(is(current, "!=")){
        
    }else if(is(current, "<")){
        
    }else if(is(current, ">")){
        
    }else if(is(current, ">=")){
        
    }else if(is(current, "<=")){
        
    }else if(is(current, "()")){
        
    }else if(is(current, "=")){
        
    }else if(is(current, "u-")){
        
    }else if(is(current, "!")){
        
    }else if(is(current, "++x")){
        
    }else if(is(current, "--x")){
        
    }else if(is(current, "x++")){
        
    }else if(is(current, "x++")){
        
    }else if(is(current, "call")){
        
    }else if(is(current, "number")){
        
    }else if(is(current, "bool")){
        
    }else if(is(current, "var")){
        
    }else if(is(current, "constant")){
        
    }

    
}

#endif