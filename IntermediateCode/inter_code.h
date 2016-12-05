#ifndef _INTER_CODE_H

#define _INTER_CODE_H

#include "gramtree.h"
#include "symboltable.h"
extern struct ast *root;
int temp_count;
int label_count;

struct InterCode
{
    char string[80];
    struct InterCode *next;
    struct InterCode *pre;
}*inter_code_head,*inter_code_tail;

void init_inter_code();
struct InterCode *translate_Exp(struct ast *ast_p,char *place);
struct InterCode *translate_Stmt(struct ast *ast_p);
struct InterCode *translate_Cond(struct ast *ast_p,char *label_true,char *label_false);
struct InterCode *translate_Args(struct ast *ast_p,struct InterCode *arg_list);
struct InterCode *translate_CompSt(struct ast *ast_p);
char * new_label();
char * new_temp();
void  print_inter_code();
struct InterCode* add_inter_code(struct InterCode *code1,int num,...);

#endif
