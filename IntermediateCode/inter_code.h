#ifndef _INTER_CODE_H

#define _INTER_CODE_H

#include "gramtree.h"
#include "symboltable.h"
extern struct ast *root;
int temp_count=0;
int label_count=0;

struct InterCode
{
    char string[30];
    struct InterCode *next_line;
    struct InterCode *pre_line;
    struct InterCode *next;
    struct InterCode *pre;
    struct InterCode *tail;
}*inter_code_head,*inter_code_tail;

void init_inter_code();
struct InterCode *translate_Exp(struct ast *ast_p,struct symbol_node *symbol_tail,char *place);
struct InterCode *translate_Stmt(struct ast *ast_p,struct symbol_node *symbol_tail);
struct InterCode *translate_Cond(struct ast *ast_p,char *label_true,char *label_false,struct symbol_node *symbol_tail);
struct InterCode *translate_Args(struct ast *ast_p,struct symbol_node *symbol_tail,struct InterCode *arg_list);
char * new_label();
char * new_temp();

#endif
