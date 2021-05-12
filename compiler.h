#ifndef _COMPILER_H_
#define _COMPILER_H_
#include "AST.h"
#include <string.h>
#include <stdio.h>
int is(const char *s, const char *type);

int generate(AST ast, FILE *out);

void compile(AST ast);
#endif