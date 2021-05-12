#include "compiler.h"

int is(const char *s, const char *type)
{
    return !strcmp(s, type);
}

int generate(AST ast, FILE *out)
{

    if (ast == NULL)
        return 0;
    /*
    main  programme command if if_else do_while while for function return   decl_args arguements
    + - * / || && == != < > >= <= () = u- ! ++x --x  x++ x-- call number bool var constant
     */
    const char *current = ast->car;

    int lines = 0;
    if (is(current, "main"))
    {
        lines += generate(ast->childs, out);
        fprintf(out, "Halt\n");
    }
    else if (is(current, "programme"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
    }
    else if (is(current, "command"))
    {
        lines += generate(ast->childs, out);
    }
    else if (is(current, "if"))
    {
    }
    else if (is(current, "if_else"))
    {
    }
    else if (is(current, "do_while"))
    {
    }
    else if (is(current, "while"))
    {
    }
    else if (is(current, "for"))
    {
    }
    else if (is(current, "function"))
    {
    }
    else if (is(current, "return"))
    {
    }
    else if (is(current, "+"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "AddiNb\n");
        lines += 1;
    }
    else if (is(current, "-"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "SubsNb\n");
        lines += 1;
    }
    else if (is(current, "*"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "MultNb\n");
        lines += 1;
    }
    else if (is(current, "/"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "DiviNb\n");
        lines += 1;
    }
    else if (is(current, "||"))
    {
    }
    else if (is(current, "&&"))
    {
    }
    else if (is(current, "=="))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "Equals\n");
        lines += 1;
    }
    else if (is(current, "!="))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "NotEql\n");
        lines += 1;
    }
    else if (is(current, "<"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "LoStNb\n");
        lines += 1;
    }
    else if (is(current, ">"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "GrStNb\n");
        lines += 1;
    }
    else if (is(current, ">="))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "GrEqNb\n");
        lines += 1;
    }
    else if (is(current, "<="))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        fprintf(out, "LoEqNb\n");
        lines += 1;
    }
    else if (is(current, "()"))
    {
        lines += generate(ast->childs, out);
    }
    else if (is(current, "="))
    {
        lines += generate(ast->childs->next, out);
        fprintf(out, "SetVar %s\n", ast->childs->str_value);
        lines += 1;
    }
    else if (is(current, "u-"))
    {
        lines += generate(ast->childs, out);
        fprintf(out, "NegaNb\n");
        lines += 1;
    }
    else if (is(current, "!"))
    {
        lines += generate(ast->childs, out);
        fprintf(out, "Not\n");
        lines += 1;
    }
    else if (is(current, "++x"))
    {
    }
    else if (is(current, "--x"))
    {
    }
    else if (is(current, "x++"))
    {
    }
    else if (is(current, "x++"))
    {
    }
    else if (is(current, "call"))
    {
    }
    else if (is(current, "number"))
    {
        fprintf(out, "CsteNb %lf\n", ast->number_value);
        lines += 1;
    }
    else if (is(current, "bool"))
    {
    }
    else if (is(current, "var"))
    {
        fprintf(out, "GetVar %s\n", ast->str_value);
        lines += 1;
    }
    else if (is(current, "constant"))
    {
    }
    return lines;
}

void compile(AST ast)
{
    FILE *f = fopen("out.js.asm", "w");
    generate(ast, f);
    fclose(f);
}