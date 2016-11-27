#include "gramtree.h"
extern struct ast *root;


struct symbol_node
{
    //int tag;1变量，2数组，3函数，4结构体,5形参
    char name[30];
    int tag;
    char type[30];
    char rtype[30];
    int pnum;
    struct symbol_node *struct_var;
    struct symbol_node *next;
    struct symbol_node *pre;
};
struct symbol_node * symboltable[4];//1变量，2数组，3函数，4结构体
struct symbol_node * var_tail;
struct symbol_node * r_var_tail;
struct symbol_node * array_tail;
struct symbol_node * r_array_tail;
struct symbol_node * func_tail;
struct symbol_node * struct_tail;

void build_symbol_table();
void parser(struct ast *p);
struct symbol_node* in_symbol_table(struct ast *p,int index);
void  eval_symbol_table();
