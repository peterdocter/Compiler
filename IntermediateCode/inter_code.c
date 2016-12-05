#include "inter_code.h"

void init_inter_code()
{
    inter_code_head=(struct InterCode*)malloc(sizeof(struct InterCode));
    inter_code_head->next=NULL;
    inter_code_head->next_line=NULL;
    inter_code_head->pre=NULL;
    inter_code_head->pre_line=NULL;
    inter_code_tail=inter_code_head;
}

struct InterCode * translate_Exp(struct ast * ast_p,struct symbol_node *symbol_tail,char *place)
{
    struct InterCode *head=(struct InterCode*)malloc(sizeof(struct InterCode));
    head->next=NULL;
    head->next_line=NULL;
    head->pre=NULL;
    head->pre_line=NULL;
    struct InterCode *tail_line=head;
    struct InterCode *tail;

    if(strcmp(ast_p->name,"INT")==0)
    {
        //新建一条语句
        tail=tail_line;
        strcpy(tail->string,place);
        tail->next=(struct InterCode*)malloc(sizeof(struct InterCode));
        tail->next->pre=tail;
        tail=tail->next;
        tail->next=NULL;

        strcpy(tail->string,":=");
        tail->next=(struct InterCode*)malloc(sizeof(struct InterCode));
        tail->next->pre=tail;
        tail=tail->next;
        tail->next=NULL;

        char str[30]
        sprintf(str,"%d",ast_p->int_value);
        strcpy(tail->string,str);
    }
    else if(!strcmp(ast_p->name,"ID")&&ast_p->right==NULL)
    {
        struct symbol_node *variable=lookup(symbol_tail,ast_p);

        tail=tail_line;
        strcpy(tail->string,place);
        tail->next=(struct InterCode*)malloc(sizeof(struct InterCode));
        tail->next->pre=tail;
        tail=tail->next;
        tail->next=NULL;

        strcpy(tail->string,":=");
        tail->next=(struct InterCode*)malloc(sizeof(struct InterCode));
        tail->next->pre=tail;
        tail=tail->next;
        tail->next=NULL;

        strcpy(tail->string,variable->name);
    }
    else if(!strcmp(ast_p->name,"Exp")&&ast_p->right!=NULL)
    {
        //运算
        if(!strcmp(ast_p->right->name,"ASSIGNOP"))
        {

        }
        else if(!strcmp(ast_p->right->name,"PLUS"))
        {

        }
        else if(!strcmp(ast_p->right->name,"MINUS"))
        {

        }
        else if(!strcmp(ast_p->right->name,"STAR"))
        {

        }
        else if(!strcmp(ast_p->right->name,"DIV"))
        {

        }
    }
    else if(!strcmp(ast_p->name,"ID")&&ast_p->right!=NULL)
    {
        // 函数
        if(!strcmp(ast_p->right->name,"LP"))
        {

        }
    }
    return head;
}

struct InterCode *translate_Stmt(struct ast *ast_p,struct symbol_node *symbol_tail)
{

}
struct InterCode *translate_Cond(struct ast *ast_p,char *label_true,char *label_false,struct symbol_node *symbol_tail)
{

}
struct InterCode *translate_Args(struct ast *ast_p,struct symbol_node *symbol_tail,struct InterCode *arg_list)
{

}
char * new_label()
{
    char *label=(char *)malloc(sizeof(char)*20);
    sprintf(label,"label%d",label_count);
    label_count++;
    return label;
}
char * new_temp()
{
    char *temp=(char *)malloc(sizeof(char)*20);
    sprintf(temp,"temp%d",label_count);
    temp_count++;
    return temp;
}
