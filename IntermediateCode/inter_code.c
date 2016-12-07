#include "inter_code.h"

void init_inter_code()
{
    inter_code_head=(struct InterCode*)malloc(sizeof(struct InterCode));
    inter_code_head->next=NULL;
    inter_code_head->pre=NULL;
    inter_code_tail=inter_code_head;
    temp_count=0;
    label_count=0;
}

struct InterCode * translate_Exp(struct ast * ast_p,char *place)
{
    struct InterCode *inter_code;
    if(!strcmp(ast_p->name,"LP"))
    {
        inter_code=translate_Exp(ast_p->right->left,place);
    }
    else if(strcmp(ast_p->name,"INT")==0)
    {
        inter_code=(struct InterCode*)malloc(sizeof(struct InterCode));
        inter_code->next=NULL;
        inter_code->pre=NULL;
        sprintf(inter_code->string,"%s := #%d",place,ast_p->int_value);
    }
    else if(!strcmp(ast_p->name,"ID")&&ast_p->right==NULL)
    {
        struct symbol_node *variable=lookup(ast_p);
        inter_code=(struct InterCode*)malloc(sizeof(struct InterCode));
        inter_code->next=NULL;
        inter_code->pre=NULL;
        sprintf(inter_code->string,"%s := %s",place,variable->name);
    }
    else if(!strcmp(ast_p->name,"Exp")&&ast_p->right!=NULL)
    {
        //运算
        if(!strcmp(ast_p->right->name,"ASSIGNOP"))
        {
            if(!strcmp(ast_p->left->name,"ID"))
            {
                if(!strcmp(ast_p->right->right->left->name,"INT"))
                {
                    struct InterCode *code1=(struct InterCode*)malloc(sizeof(struct InterCode));
                    code1->next=NULL;
                    code1->pre=NULL;
                    sprintf(code1->string,"%s := #%d",ast_p->left->content,ast_p->right->right->left->int_value);

                    if(place!=NULL)
                    {
                        struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                        code3->next=NULL;
                        code3->pre=NULL;
                        sprintf(code3->string,"%s := %s",place,ast_p->left->content);

                        return add_inter_code(code1,1,code3);
                    }
                    else
                          return code1;
                }
                struct symbol_node *variable=lookup(ast_p->left);
                char   *t1=new_temp();
                struct InterCode *code1=translate_Exp(ast_p->right->right->left,t1);

                struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
                code2->next=NULL;
                code2->pre=NULL;
                sprintf(code2->string,"%s := %s",variable->name,t1);

                if(place!=NULL)
                {
                    struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                    code3->next=NULL;
                    code3->pre=NULL;
                    sprintf(code3->string,"%s := %s",place,variable->name);

                    inter_code=add_inter_code(code1,2,code2,code3);
                }
                else
                {
                    inter_code=add_inter_code(code1,1,code2);
                }
            }
        }
        else if(!strcmp(ast_p->right->name,"PLUS"))
        {
            char *t1=new_temp();
            char *t2=new_temp();
            struct InterCode *code1=translate_Exp(ast_p->left,t1);
            struct InterCode *code2=translate_Exp(ast_p->right->right->left,t2);

            if(place!=NULL)
            {
                struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                code3->next=NULL;
                code3->pre=NULL;
                sprintf(code3->string,"%s := %s + %s",place,t1,t2);

                inter_code=add_inter_code(code1,2,code2,code3);
            }
            else
            {
                inter_code=add_inter_code(code1,1,code2);
            }

        }
        else if(!strcmp(ast_p->right->name,"MINUS"))
        {
            if(!strcmp(ast_p->left->name,"ID"))
            {
                if(!strcmp(ast_p->right->right->left->name,"INT"))
                {
                    if(place!=NULL)
                    {
                        struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                        code3->next=NULL;
                        code3->pre=NULL;
                        sprintf(code3->string,"%s := %s - #%d",place,ast_p->left->content,ast_p->right->right->left->int_value);
                        return code3;
                    }
                }
                else if(!strcmp(ast_p->right->right->left->name,"ID"))
                {
                    if(place!=NULL)
                    {
                        struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                        code3->next=NULL;
                        code3->pre=NULL;
                        sprintf(code3->string,"%s := %s - %s",place,ast_p->left->content,ast_p->right->right->left->content);
                        return code3;
                    }
                }
            }
            char *t1=new_temp();
            char *t2=new_temp();
            struct InterCode *code1=translate_Exp(ast_p->left,t1);
            struct InterCode *code2=translate_Exp(ast_p->right->right->left,t2);

            if(place!=NULL)
            {
                struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                code3->next=NULL;
                code3->pre=NULL;
                sprintf(code3->string,"%s := %s - %s",place,t1,t2);

                inter_code=add_inter_code(code1,2,code2,code3);
            }
            else
            {
                inter_code=add_inter_code(code1,1,code2);
            }
        }
        else if(!strcmp(ast_p->right->name,"STAR"))
        {
            char *t1=new_temp();
            char *t2=new_temp();
            struct InterCode *code1=translate_Exp(ast_p->left,t1);
            struct InterCode *code2=translate_Exp(ast_p->right->right->left,t2);

            if(place!=NULL)
            {
                struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                code3->next=NULL;
                code3->pre=NULL;
                sprintf(code3->string,"%s := %s * %s",place,t1,t2);

                inter_code=add_inter_code(code1,2,code2,code3);
            }
            else
            {
                inter_code=add_inter_code(code1,1,code2);
            }
        }
        else if(!strcmp(ast_p->right->name,"DIV"))
        {
            char *t1=new_temp();
            char *t2=new_temp();
            struct InterCode *code1=translate_Exp(ast_p->left,t1);
            struct InterCode *code2=translate_Exp(ast_p->right->right->left,t2);

            if(place!=NULL)
            {
                struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                code3->next=NULL;
                code3->pre=NULL;
                sprintf(code3->string,"%s := %s / %s",place,t1,t2);

                inter_code=add_inter_code(code1,2,code2,code3);
            }
            else
            {
                inter_code=add_inter_code(code1,1,code2);
            }
        }
    }
    else if(!strcmp(ast_p->name,"MINUS"))
    {
        char *t1=new_temp();
        struct InterCode *code1=translate_Exp(ast_p->right->left,t1);

        struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
        code2->next=NULL;
        code2->pre=NULL;
        sprintf(code2->string,"%s := #0 - %s",place,t1);

        inter_code=add_inter_code(code1,1,code2);
    }
    else if(!strcmp(ast_p->name,"ID")&&ast_p->right!=NULL&&!strcmp(ast_p->right->name,"LP"))
    {
        // 函数
        if(!strcmp(ast_p->right->right->name,"RP"))
        {
            struct symbol_node *function=lookup(ast_p);
            struct InterCode *code1=(struct InterCode*)malloc(sizeof(struct InterCode));
            code1->next=NULL;
            code1->pre=NULL;
            if(!strcmp(function->name,"read"))
            {
                sprintf(code1->string,"READ %s",place);
            }
            else
            {
                sprintf(code1->string,"%s := CALL %s",place,function->name);
            }
            inter_code=code1;
        }
        else
        {
            struct symbol_node *function=lookup(ast_p);

            struct InterCode *arg_list=(struct InterCode*)malloc(sizeof(struct InterCode));
            arg_list->next=NULL;
            arg_list->pre=NULL;

            struct InterCode *code1=translate_Args(ast_p->right->right->left,arg_list);

            if(!strcmp(function->name,"write"))
            {
                struct InterCode *write_arg=(struct InterCode*)malloc(sizeof(struct InterCode));
                write_arg->next=NULL;
                write_arg->pre=NULL;
                sprintf(write_arg->string,"WRITE %s",arg_list->string);
                inter_code=add_inter_code(code1,1,write_arg);
                return inter_code;
            }
            struct InterCode *p=arg_list;
            while (p->next!=NULL)
            {
                p=p->next;
            }

            p=p->pre;
            while(p!=NULL)
            {
                struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
                code2->next=NULL;
                code2->pre=NULL;
                sprintf(code2->string,"ARG %s",p->string);
                code1=add_inter_code(code1,1,code2);
                p=p->pre;
            }
            struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
            code2->next=NULL;
            code2->pre=NULL;
            sprintf(code2->string,"%s := CALL %s",place,function->name);
            inter_code=add_inter_code(code1,1,code2);
        }
    }
    else if(!strcmp(ast_p->name,"Exp")&&ast_p->right!=NULL&&!strcmp(ast_p->right->name,"LB"))
    {
        //数组
    }
    return inter_code;
}

struct InterCode *translate_Stmt(struct ast *ast_p)
{
    struct InterCode *inter_code=NULL;
    if(!strcmp(ast_p->name,"Exp"))
    {
        inter_code=translate_Exp(ast_p->left,NULL);
    }
    else if(!strcmp(ast_p->name,"CompSt"))
    {
        inter_code=translate_CompSt(ast_p->left);
    }
    else if(!strcmp(ast_p->name,"RETURN"))
    {
        if(!strcmp(ast_p->right->left->name,"ID"))
        {
            struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
            code2->next=NULL;
            code2->pre=NULL;
            sprintf(code2->string,"RETURN %s",ast_p->right->left->content);
            return code2;
        }

        if(!strcmp(ast_p->right->left->name,"INT"))
        {
            struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
            code2->next=NULL;
            code2->pre=NULL;
            sprintf(code2->string,"RETURN #%d",ast_p->right->left->int_value);
            return code2;
        }
        char *t1=new_temp();
        struct InterCode *code1=translate_Exp(ast_p->right->left,t1);
        struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
        code2->next=NULL;
        code2->pre=NULL;
        sprintf(code2->string,"RETURN %s",t1);

        inter_code=add_inter_code(code1,1,code2);
    }
    else if(!strcmp(ast_p->name,"IF"))
    {
        struct ast *exp_p=ast_p->right->right;
        struct ast *stmt_p=exp_p->right->right;
        if(stmt_p->right==NULL)
        {
            char *label1=new_label();
            char *label2=new_label();
            struct InterCode *code1=translate_Cond(exp_p->left,label1,label2);
            struct InterCode *code2=translate_Stmt(stmt_p->left);

            struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
            code3->next=NULL;
            code3->pre=NULL;
            sprintf(code3->string,"LABEL %s :",label1);

            struct InterCode *code4=(struct InterCode*)malloc(sizeof(struct InterCode));
            code4->next=NULL;
            code4->pre=NULL;
            sprintf(code4->string,"LABEL %s :",label2);

            inter_code=add_inter_code(code1,3,code3,code2,code4);
        }
        else
        {
            struct ast *stmt_p_2=stmt_p->right->right;
            char *label1=new_label();
            char *label2=new_label();
            char *label3=new_label();

            struct InterCode *code1=translate_Cond(exp_p->left,label1,label2);
            struct InterCode *code2=translate_Stmt(stmt_p->left);
            struct InterCode *code3=translate_Stmt(stmt_p_2->left);

            struct InterCode *code4=(struct InterCode*)malloc(sizeof(struct InterCode));
            code4->next=NULL;
            code4->pre=NULL;
            sprintf(code4->string,"LABEL %s :",label1);

            struct InterCode *code5=(struct InterCode*)malloc(sizeof(struct InterCode));
            code5->next=NULL;
            code5->pre=NULL;
            sprintf(code5->string,"GOTO %s",label3);

            struct InterCode *code6=(struct InterCode*)malloc(sizeof(struct InterCode));
            code6->next=NULL;
            code6->pre=NULL;
            sprintf(code6->string,"LABEL %s :",label2);

            struct InterCode *code7=(struct InterCode*)malloc(sizeof(struct InterCode));
            code7->next=NULL;
            code7->pre=NULL;
            sprintf(code7->string,"LABEL %s :",label3);

            inter_code=add_inter_code(code1,6,code4,code2,code5,code6,code3,code7);
        }
    }
    else if(!strcmp(ast_p->name,"WHILE"))
    {
        char *label1=new_label();
        char *label2=new_label();
        char *label3=new_label();

        struct InterCode *code1=translate_Cond(ast_p->right->right->left,label2,label3);
        struct InterCode *code2=translate_Stmt(ast_p->right->right->right->right->left);

        struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
        code3->next=NULL;
        code3->pre=NULL;
        sprintf(code3->string,"LABEL %s :",label1);

        struct InterCode *code4=(struct InterCode*)malloc(sizeof(struct InterCode));
        code4->next=NULL;
        code4->pre=NULL;
        sprintf(code4->string,"LABEL %s :",label2);

        struct InterCode *code5=(struct InterCode*)malloc(sizeof(struct InterCode));
        code5->next=NULL;
        code5->pre=NULL;
        sprintf(code5->string,"GOTO %s",label1);

        struct InterCode *code6=(struct InterCode*)malloc(sizeof(struct InterCode));
        code6->next=NULL;
        code6->pre=NULL;
        sprintf(code6->string,"LABEL %s :",label2);

        inter_code=add_inter_code(code3,5,code1,code4,code2,code5,code6);
    }
    return inter_code;
}
struct InterCode *translate_Cond(struct ast *ast_p,char *label_true,char *label_false)
{
    struct InterCode *inter_code=NULL;

    if(!strcmp(ast_p->name,"NOT"))
    {
        inter_code=translate_Cond(ast_p->right->left,label_false,label_true);
    }
    else if(ast_p->right!=NULL&&!strcmp(ast_p->right->name,"RELOP"))
    {
        if(!strcmp(ast_p->left->name,"ID"))
        {
            if(!strcmp(ast_p->right->right->left->name,"INT"))
            {
                struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                code3->next=NULL;
                code3->pre=NULL;
                sprintf(code3->string,"IF %s %s #%d GOTO %s",ast_p->left->content,ast_p->right->content,ast_p->right->right->left->int_value,label_true);

                struct InterCode *code4=(struct InterCode*)malloc(sizeof(struct InterCode));
                code4->next=NULL;
                code4->pre=NULL;
                sprintf(code4->string,"GOTO %s",label_false);

                return add_inter_code(code3,1,code4);
            }
            else if(!strcmp(ast_p->right->right->left->name,"ID"))
            {
                struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                code3->next=NULL;
                code3->pre=NULL;
                sprintf(code3->string,"IF %s %s %s GOTO %s",ast_p->left->content,ast_p->right->content,ast_p->right->right->left->content,label_true);

                struct InterCode *code4=(struct InterCode*)malloc(sizeof(struct InterCode));
                code4->next=NULL;
                code4->pre=NULL;
                sprintf(code4->string,"GOTO %s",label_false);

                return add_inter_code(code3,1,code4);
            }
            else
            {
                char *t1=new_temp();
                struct InterCode *code1=translate_Exp(ast_p->right->right->left,t1);

                struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
                code2->next=NULL;
                code2->pre=NULL;
                sprintf(code2->string,"IF %s %s %s GOTO %s",ast_p->left->content,ast_p->right->content,t1,label_true);

                struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
                code3->next=NULL;
                code3->pre=NULL;
                sprintf(code3->string,"GOTO %s",label_false);

                return add_inter_code(code1,2,code2,code3);
            }
        }
        char *t1=new_temp();
        char *t2=new_temp();

        struct InterCode *code1=translate_Exp(ast_p->left,t1);
        struct InterCode *code2=translate_Exp(ast_p->right->right->left,t2);

        struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
        code3->next=NULL;
        code3->pre=NULL;
        sprintf(code3->string,"IF %s %s %s GOTO %s",t1,ast_p->right->content,t2,label_true);

        struct InterCode *code4=(struct InterCode*)malloc(sizeof(struct InterCode));
        code4->next=NULL;
        code4->pre=NULL;
        sprintf(code4->string,"GOTO %s",label_false);

        inter_code=add_inter_code(code1,3,code2,code3,code4);
    }
    else if(ast_p->right!=NULL&&!strcmp(ast_p->right->name,"AND"))
    {
        char *label1=new_label();

        struct InterCode *code1=translate_Cond(ast_p->left,label1,label_false);
        struct InterCode *code2=translate_Cond(ast_p->right->right->left,label_true,label_false);

        struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
        code3->next=NULL;
        code3->pre=NULL;
        sprintf(code3->string,"LABEL %s :",label1);

        inter_code=add_inter_code(code1,2,code3,code2);
    }
    else if(ast_p->right!=NULL&&!strcmp(ast_p->right->name,"OR"))
    {
        char *label1=new_label();

        struct InterCode *code1=translate_Cond(ast_p->left,label_true,label1);
        struct InterCode *code2=translate_Cond(ast_p->right->right->left,label_true,label_false);

        struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
        code3->next=NULL;
        code3->pre=NULL;
        sprintf(code3->string,"LABEL %s :",label1);

        inter_code=add_inter_code(code1,2,code3,code2);
    }
    else
    {
        char *t1=new_temp();
        struct InterCode *code1=translate_Exp(ast_p,t1);

        struct InterCode *code2=(struct InterCode*)malloc(sizeof(struct InterCode));
        code2->next=NULL;
        code2->pre=NULL;
        sprintf(code2->string,"IF %s != #0 GOTO %s",t1,label_true);

        struct InterCode *code3=(struct InterCode*)malloc(sizeof(struct InterCode));
        code3->next=NULL;
        code3->pre=NULL;
        sprintf(code3->string,"GOTO %s",label_false);

        inter_code=add_inter_code(code1,2,code2,code3);
    }
    return inter_code;
}


struct InterCode *translate_Args(struct ast *ast_p,struct InterCode *arg_list)
{
    if(!strcmp(ast_p->name,"Exp")&&ast_p->right==NULL)
    {
        char *t1=new_temp();
        struct InterCode* code1=translate_Exp(ast_p->left,t1);
        struct InterCode* p=arg_list;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        strcpy(p->string,t1);

        p->next=(struct InterCode*)malloc(sizeof(struct InterCode));
        p->next->pre=p;
        p=p->next;
        p->next=NULL;
        return code1;
    }
    else
    {
        char *t1=new_temp();
        struct InterCode *code1=translate_Exp(ast_p->left,t1);
        struct InterCode *p=arg_list;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        strcpy(p->string,t1);
        p->next=(struct InterCode*)malloc(sizeof(struct InterCode));
        p->next->pre=p;
        p=p->next;
        p->next=NULL;

        struct InterCode *code2=translate_Args(ast_p->right->right->left,p);

        return add_inter_code(code1,1,code2);
    }
}

struct InterCode *translate_CompSt(struct ast *ast_p)
{
    struct InterCode* inter_code=NULL;
    struct ast *p=ast_p;
    while(p!=NULL)
    {
        if(!strcmp(p->name,"StmtList")&&p->line!=-1)
        {
            struct InterCode *code=translate_Stmt(p->left->left);
            if(inter_code==NULL)
                inter_code=code;
            else
                inter_code=add_inter_code(inter_code,1,code);
            p=p->left;
        }
        p=p->right;
    }
    return inter_code;
}

struct InterCode* translate_Func(struct ast *ast_p)
{
    struct InterCode *inter_code=(struct InterCode*)malloc(sizeof(struct InterCode));
    inter_code->next=NULL;
    inter_code->pre=NULL;
    sprintf(inter_code->string,"\nFUNCTION %s :",ast_p->content);
    return inter_code;
}

struct InterCode* translate_VarDec(struct ast *ast_p)
{
    struct InterCode *inter_code=(struct InterCode*)malloc(sizeof(struct InterCode));
    inter_code->next=NULL;
    inter_code->pre=NULL;
    sprintf(inter_code->string,"PARAM %s",ast_p->content);
    return inter_code;
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
    sprintf(temp,"temp%d",temp_count);
    temp_count++;
    return temp;
}

void print_inter_code()
{
    FILE *f;
    f=fopen("output/output.txt","w");
    struct InterCode *p=inter_code_head->next;
    while(p!=NULL)
    {
        printf("%s\n",p->string);
        fprintf(f,"%s\n",p->string);
        p=p->next;
    }
    fclose(f);
}

struct InterCode* add_inter_code(struct InterCode *code1,int num,...)
{
    va_list valist;
    struct InterCode *head=code1;
    struct InterCode *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    va_start(valist, num);
    for(int i=0;i<num;++i)
    {
        struct InterCode *temp=va_arg(valist,struct InterCode*);
        p->next=temp;
        temp->pre=p;
        while(p->next!=NULL)
        {
            p=p->next;
        }
    }
    return head;
}
