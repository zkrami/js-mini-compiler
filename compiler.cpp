#include "compiler.hpp"

int is(const char *s, const char *type)
{
    return !strcmp(s, type);
}

int generate(AST ast, stringstream& out)
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
        out <<  "Halt\n" ; 
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

        //  IF '(' expression ')' command ELSE command  { $$= newTernaryAST("if_else" , $3 , $5 , $7 ); }


         // @Cast ToBool
        lines += generate(ast->childs, out);
        // fprintf(out, "ConJmp \n" );


        /*

            ConJmp 3
            CsteBo False
            SetVar y
            Jump 8


            GetVar x
            TypeOf
            Case
            Jump 1
            BoToNb
            CsteNb 1
            AddiNb
            SetVar y
            Halt
        */
       

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
        out << "AddiNb\n"; 
        lines += 1;
    }
    else if (is(current, "-"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        out << "SubsNb\n" ; 
        lines += 1;
    }
    else if (is(current, "*"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        out << "MultNb\n" ; 
        lines += 1;
    }
    else if (is(current, "/"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        out <<  "DiviNb\n" ; 
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
        out <<  "Equals\n" ;
        lines += 1;
    }
    else if (is(current, "!="))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        out << "NotEql\n" ; 
        lines += 1;
    }
    else if (is(current, "<"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        out << "LoStNb\n" ; 
        lines += 1;
    }
    else if (is(current, ">"))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
         out <<  "GrStNb\n" ; 
        lines += 1;
    }
    else if (is(current, ">="))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        out <<  "GrEqNb\n";
        lines += 1;
    }
    else if (is(current, "<="))
    {
        lines += generate(ast->childs, out);
        lines += generate(ast->childs->next, out);
        out <<  "LoEqNb\n";
        lines += 1;
    }
    else if (is(current, "()"))
    {
        lines += generate(ast->childs, out);
    }
    else if (is(current, "="))
    {
        lines += generate(ast->childs->next, out);
        out <<  "SetVar " <<  ast->childs->str_value << "\n";
        lines += 1;
    }
    else if (is(current, "u-"))
    {
        lines += generate(ast->childs, out);
        out <<  "NegaNb\n";
        lines += 1;
    }
    else if (is(current, "!"))
    {
        lines += generate(ast->childs, out);
        out <<  "Not\n";
        lines += 1;
    }
    else if (is(current, "++x"))
    {

        out <<  "GetVar " <<  ast->childs->str_value << "\n";
        out <<  "CsteNb 1\n";
        out <<  "AddiNb\n";
        out <<  "Copy\n";
        out <<  "SetVar " <<  ast->childs->str_value << "\n";

        lines += 5;
    }
    else if (is(current, "--x"))
    {
        out <<  "GetVar " << ast->childs->str_value << "\n";
        out <<  "CsteNb 1\n";
        out <<  "SubsNb\n";
        out <<  "Copy\n";
        out <<  "SetVar " << ast->childs->str_value << "\n";

        lines += 5;
    }
    else if (is(current, "x++"))
    {
        out <<  "GetVar " << ast->childs->str_value << "\n";
        out <<  "Copy\n";
        out <<  "CsteNb 1\n";
        out <<  "AddiNb\n";
        out <<  "SetVar " << ast->childs->str_value << "\n";
        lines += 5;
    }
    else if (is(current, "x--"))
    {
        out <<  "GetVar " << ast->childs->str_value << "\n";
        out <<  "Copy\n";
        out <<  "CsteNb 1\n";
        out <<  "SubsNb\n";
        out <<  "SetVar " << ast->childs->str_value << "\n";
        lines += 5;
    }
    else if (is(current, "call"))
    {
    }
    else if (is(current, "number"))
    {
        out <<  "CsteNb " <<  ast->number_value << "\n";
        lines += 1;
    }
    else if (is(current, "bool"))
    {
        out <<  "CsteBo " << ( ast->boolean_value ? "true" : "false" ) << "\n";
        lines += 1;
         
    }
    else if (is(current, "var"))
    {
        out <<  "GetVar " << ast->str_value << "\n";
        lines += 1;
    }
    else if (is(current, "constant"))
    {
        if (is(ast->str_value, "NaN") || is(ast->str_value, "Infinity"))
        {
            out <<  "CsteNb " << ast->str_value << "\n";
            lines += 1;
        }
        else if (is(ast->str_value, "undefined"))
        {
        }
    }
    return lines;
}

void compile(AST ast)
{
    FILE *f = fopen("out.js.asm", "w");
    stringstream result; 
    generate(ast, result);
    fputs(result.str().c_str() , f); 
    fclose(f);
}