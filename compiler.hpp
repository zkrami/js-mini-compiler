#ifndef _COMPILER_H_
#define _COMPILER_H_
extern "C" { 
    #include "AST.h"
}
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std; 
int is(const char *s, const char *type);

int generate(AST ast, stringstream& out);

void compile(AST ast);
#endif