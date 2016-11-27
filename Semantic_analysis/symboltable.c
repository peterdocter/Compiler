#include "symboltable.h"

void build_symbol_table()
{
    symboltable[0]=(struct symbol_node*)malloc(sizeof(struct symbol_node));
    var_tail=symboltable[0];
    symboltable[1]=(struct symbol_node*)malloc(sizeof(struct symbol_node));
    array_tail=symboltable[1];
    symboltable[2]=(struct symbol_node*)malloc(sizeof(struct symbol_node));
    func_tail=symboltable[2];
    symboltable[3]=(struct symbol_node*)malloc(sizeof(struct symbol_node));
    struct_tail=symboltable[3];
    parser(root);
    eval_symbol_table();
}

void parser(struct ast *p)
{
    if(p==NULL||p->line==-1)
        return;
    printf("%s\n",p->name);
    if(strcmp(p->name,"Specifier")==0)
    {
        struct ast *right=p->right;
        if(strcmp(right->name,"FunDec")==0)
        {
            //函数定义
            if(in_symbol_table(right,2)!=NULL)
            {
                printf("Error type 4 at Line %d: Redefined function \"%s\".\n",right->line,right->content);
            }
            else{
                func_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                func_tail=func_tail->next;
                func_tail->next=NULL;
                func_tail->pnum=0;
                strcpy(func_tail->rtype,p->type);
                strcpy(func_tail->name,right->content);
            }
            p=right;
        }
        else if(strcmp(right->name,"ExtDecList")==0)
        {
            //全局变量
            struct ast *left=right->left;
            while (left!=NULL)
            {
                if(strcmp(left->name,"VarDec")==0)
                {
                    if(in_symbol_table(left,0)!=NULL)
                    {
                        printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",left->line,left->content);
                    }
                    else{
                        var_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                        var_tail=var_tail->next;
                        var_tail->next=NULL;
                        strcpy(var_tail->type,p->type);
                        strcpy(var_tail->name,right->content);
                    }
                }
                left=left->right;
            }
            p=right->left;
        }
        else if(strcmp(right->name,"SEMI")==0)
        {
            //结构体定义
        }
        else if(strcmp(right->name,"VarDec")==0)
        {
            //函数参数
            func_tail->pnum+=1;
            var_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
            var_tail=var_tail->next;
            var_tail->next=NULL;
            strcpy(var_tail->type,p->type);
            strcpy(var_tail->name,right->content);
        }
        else if(strcmp(right->name,"DecList"))
        {
            //函数内变量定义
        }
    }
    else if(strcmp(p->name,"CompSt")==0)
    {

    }
    parser(p->left);
    parser(p->right);
}

struct symbol_node* in_symbol_table(struct ast *p,int index)
{
    struct symbol_node *symbol_p=symboltable[index]->next;
    while(symbol_p!=NULL)
    {
        if(!strcmp(symbol_p->name,p->content))
        {
            return symbol_p;
        }
        symbol_p=symbol_p->next;
    }
    return NULL;
}

void eval_symbol_table()
{
    for(int i=0;i<4;++i)
    {
        struct symbol_node *p=symboltable[i]->next;
        while(p!=NULL)
        {
            printf("%s-",p->name);
            if(i==2)
            {
                printf(" %s %d ",p->rtype,p->pnum);
            }
            else
            {
                printf(" %s ",p->type);
            }
            p=p->next;
        }
        printf("\n");
    }
}
