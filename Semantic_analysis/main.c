#include "gramtree.h"
#include "symboltable.h"
extern struct ast *root;

int main(int argc, char const *argv[])
{
    if(argc>1)
    {
        FILE * f= fopen(argv[1],"r");
        if(!f)
        {
            perror(argv[1]);
            return 1;
        }
        //yydebug=1;
        yyrestart(f);
        yyparse();
        build_symbol_table();
        eval(root,0);
        return 0;
    }
    yyparse();
    return 0;
}
