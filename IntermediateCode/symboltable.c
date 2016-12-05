#include "symboltable.h"

void build_symbol_table()
{
    symboltable[0]=(struct symbol_node*)malloc(sizeof(struct symbol_node));
    var_tail=symboltable[0];
    var_tail->pre=NULL;
    symboltable[1]=(struct symbol_node*)malloc(sizeof(struct symbol_node));
    array_tail=symboltable[1];
    array_tail->pre=NULL;
    symboltable[2]=(struct symbol_node*)malloc(sizeof(struct symbol_node));
    func_tail=symboltable[2];
    symboltable[3]=(struct symbol_node*)malloc(sizeof(struct symbol_node));
    struct_tail=symboltable[3];
    parser(root);
}

struct ast * parser_Specifier(struct ast *p)
{
    struct ast *right=p->right;
    if(strcmp(right->name,"FunDec")==0)
    {
        //函数定义
        if(strcmp(right->right->name,"SEMI")==0)
        {
            p=right->right;
        }
        else
        {
            if(in_symbol_table(right,2)!=NULL)
            {
                printf("Error type 4 at Line %d: Redefined function \"%s\".\n",right->line,right->content);
            }
            else{
                func_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                func_tail->next->pre=func_tail;
                func_tail=func_tail->next;
                func_tail->next=NULL;
                func_tail->tag=3;
                func_tail->pnum=0;
                strcpy(func_tail->rtype,p->type);
                strcpy(func_tail->name,right->content);
            }
            p=right;
        }
    }
    else if(strcmp(right->name,"ExtDecList")==0)
    {
        //全局变量
        struct ast *left=right->left;
        while (left!=NULL)
        {
            if(strcmp(p->type,"int")!=0&&strcmp(p->type,"float")!=0)
            {
                struct symbol_node *struct_symbol=in_symbol_table(p,3);
                if(struct_symbol==NULL)
                {
                    printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->line,p->content);
                    break;
                }
            }
            if(strcmp(left->name,"VarDec")==0)
            {
                    if(in_symbol_table(left,0)!=NULL)
                    {
                        printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",left->line,left->content);
                    }
                    else
                    {
                        var_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                        var_tail->next->pre=var_tail;
                        var_tail=var_tail->next;
                        var_tail->tag=1;
                        var_tail->next=NULL;
                        strcpy(var_tail->type,p->type);
                        strcpy(var_tail->name,left->content);
                    }
            }
            else
            {
                if(in_symbol_table(left,1)!=NULL)
                {
                    printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",left->line,left->content);
                }
                else
                {
                    array_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                    array_tail->next->pre=array_tail;
                    array_tail=array_tail->next;
                    array_tail->tag=2;
                    array_tail->next=NULL;
                    strcpy(array_tail->type,p->type);
                    strcpy(array_tail->name,left->left->content);
                }
            }
            left=left->right;
            if(left!=NULL)
            {
                left=left->right;
                left=left->left;
            }
        }
        p=right->right;
    }
    else if(strcmp(right->name,"SEMI")==0)
    {
        //结构体定义
        p=p->left->left;
        right=p->right;
        if(in_symbol_table(right->left,-1)!=NULL)
        {
            printf("Error type 16 at Line %d: Duplicated name \"%s\".\n",p->line,right->left->content);
        }
        else
        {
            struct_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
            struct_tail->next->pre=struct_tail;
            struct_tail=struct_tail->next;
            struct_tail->tag=4;
            struct_tail->next=NULL;
            strcpy(struct_tail->name,right->left->content);
            p=right->right->right->left;
            struct_tail->struct_var=(struct symbol_node*)malloc(sizeof(struct symbol_node));
            struct symbol_node *struct_var_tail=struct_tail->struct_var;
            while (p!=NULL)
            {
                if(strcmp(p->name,"Def")==0)
                {
                    struct ast *left=p->left;
                    char specifier_type[30];
                    strcpy(specifier_type,left->type);
                    left=left->right->left;
                    while(left!=NULL)
                    {
                        struct ast *var=left->left;
                        if(strcmp(var->left->name,"ID")==0)
                        {
                            //变量
                            if(in_struct_symbol_table(var,struct_tail->struct_var)!=NULL)
                            {
                                printf("Error type 15 at Line %d: Redefined field \"%s\".\n",p->line,var->content);
                            }
                            else
                            {
                                struct_var_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                                struct_var_tail->next->pre=struct_var_tail;
                                struct_var_tail=struct_var_tail->next;
                                struct_var_tail->tag=1;
                                struct_var_tail->next=NULL;
                                strcpy(struct_var_tail->type,specifier_type);
                                strcpy(struct_var_tail->name,var->left->content);
                            }
                        }
                        else
                        {
                            //数组
                            if(in_struct_symbol_table(var,struct_tail->struct_var)!=NULL)
                            {
                                printf("Error type 15 at Line %d: Redefined field \"%s\".\n",p->line,var->content);
                            }
                            else
                            {
                                struct_var_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                                struct_var_tail->next->pre=struct_var_tail;
                                struct_var_tail=struct_var_tail->next;
                                struct_var_tail->tag=2;
                                struct_var_tail->next=NULL;
                                strcpy(struct_var_tail->type,specifier_type);
                                strcpy(struct_var_tail->name,left->left->content);
                            }
                        }
                        left=left->right;
                        if(left!=NULL)
                        {
                            left=left->right;
                            left=left->left;
                        }
                    }
                }
                p=p->right;
                if(p!=NULL)
                {
                    p=p->left;
                }
            }
        }
        p=NULL;
    }
    else if(strcmp(right->name,"VarDec")==0)
    {
        //函数参数
        func_tail->pnum+=1;
        var_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
        var_tail->next->pre=var_tail;
        var_tail=var_tail->next;
        var_tail->tag=5;
        var_tail->next=NULL;
        strcpy(var_tail->type,p->type);
        strcpy(var_tail->name,right->content);

    }
    else if(strcmp(right->name,"DecList")==0)
    {
        //函数内变量定义
        struct ast *left=right->left;
        while(left!=NULL)
        {
            if(strcmp(p->type,"int")!=0&&strcmp(p->type,"float")!=0)
            {
                struct symbol_node *struct_symbol=in_symbol_table(p,3);
                if(struct_symbol==NULL)
                {
                    printf("Error type 17 at Line %d: Undefined structure \"%s\".\n",p->line,p->content);
                    break;
                }
            }
            struct ast *var=left->left;
            if(strcmp(var->left->name,"ID")==0)
            {
                //变量
                if(var->right!=NULL)
                {
                    struct ast *type=var->right->right->left;
                    if(strcmp(type->name,"ID")==0)
                    {
                        struct symbol_node *symbol=in_symbol_table(type,0);
                        if(symbol!=NULL)
                        {
                            if(strcmp(p->type,symbol->type)!=0)
                            {
                                printf("Error type 5 at Line %d: Type mismatched for assignment.\n",left->line);
                            }
                        }
                        else
                        {
                            printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",left->line,type->content);
                        }
                    }
                    else if(strcmp(type->name,"INT")==0)
                    {
                        if(strcmp(p->type,"int")!=0)
                        {
                            printf("Error type 5 at Line %d: Type mismatched for assignment.\n",left->line);
                        }
                    }
                    else if(strcmp(type->name,"FLOAT")==0)
                    {
                        if(strcmp(p->type,"float")!=0)
                        {
                            printf("Error type 5 at Line %d: Type mismatched for assignment.\n",left->line);
                        }
                    }
                }
                if(in_symbol_table(var,0)!=NULL)
                {
                    printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",left->line,left->content);
                }
                else
                {
                    var_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                    var_tail->next->pre=var_tail;
                    var_tail=var_tail->next;
                    var_tail->tag=1;
                    var_tail->next=NULL;
                    strcpy(var_tail->type,p->type);
                    strcpy(var_tail->name,var->content);
                }
            }
            else
            {
                //数组
                if(in_symbol_table(left,1)!=NULL)
                {
                    printf("Error type 3 at Line %d: Redefined variable \"%s\".\n",left->line,left->content);
                }
                else
                {
                    array_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
                    array_tail->next->pre=array_tail;
                    array_tail=array_tail->next;
                    array_tail->tag=2;
                    array_tail->next=NULL;
                    strcpy(array_tail->type,p->type);
                    strcpy(array_tail->name,left->left->content);
                }
            }
            left=left->right;
            if(left!=NULL)
            {
                left=left->right;
                left=left->left;
            }
        }
        p=right->right;
    }
    return p;
}


struct ast * parser_RETURN(struct ast *p)
{
    struct ast *right=p->right;
    struct ast *left=right->left;
    if(strcmp(left->name,"ID")==0)
    {
        struct symbol_node *symbol=in_symbol_table(left,0);
        if(symbol==NULL)
        {
            printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",p->line,left->content);
        }
        else if(strcmp(func_tail->rtype,symbol->type)!=0)
        {
            printf("Error type 8 at Line %d: Type mismatched for return.\n",p->line);
        }
    }
    else if(strcmp(left->name,"INT")==0)
    {
        if(strcmp(func_tail->rtype,"int")!=0)
        {
            printf("Error type 8 at Line %d: Type mismatched for return.\n",p->line);
        }
    }
    else if(strcmp(left->name,"FLOAT")==0)
    {
        if(strcmp(func_tail->rtype,"float")!=0)
        {
            printf("Error type 8 at Line %d: Type mismatched for return.\n",p->line);
        }
    }
    p=right;
    return p;
}

struct ast *parser_Exp(struct ast *p)
{
    p=p->left;
    struct ast *left=p->left;
    struct ast *right=p->right;
    //赋值
    if(right!=NULL && strcmp(right->name,"ASSIGNOP")==0)
    {
        if(strcmp(left->name,"ID")==0)
        {
            struct symbol_node *symbol=in_symbol_table(left,0);
            if(symbol==NULL)
            {
                printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",p->line,left->content);
            }
            else
            {
                //判断类型是否匹配
                struct ast *right_exp=right->right;
                if(strcmp(right_exp->left->name,"ID")==0)
                {
                    struct symbol_node *right_symbol=in_symbol_table(right_exp->left,-1);
                    if(right_symbol->tag==3)
                    {
                        if(strcmp(symbol->type,right_symbol->rtype)!=0)
                        {
                            printf("Error type 5 at Line %d: Type mismatched for assignment.\n",p->line);
                        }
                    }
                    else if(right_symbol->tag==1)
                    {
                        if(strcmp(symbol->type,right_symbol->rtype)!=0)
                        {
                            printf("Error type 5 at Line %d: Type mismatched for assignment.\n",p->line);
                        }
                    }
                    //printf("%s\n",right_exp->left->name);
                }
                else if(strcmp(right_exp->left->name,"INT")==0)
                {
                    if(strcmp(symbol->type,"int")!=0)
                    {
                        printf("Error type 5 at Line %d: Type mismatched for assignment.\n",p->line);
                    }
                }
                else if(strcmp(right_exp->left->name,"FLOAT")==0)
                {
                    if(strcmp(symbol->type,"float")!=0)
                    {
                        printf("Error type 5 at Line %d: Type mismatched for assignment.\n",p->line);
                    }
                }
            }
        }
        else if(strcmp(left->name,"INT")==0)
        {
            printf("Error type 6 at Line %d: The left-hand side of an assignment must be a varia- ble.\n",p->line);
        }
        else if(strcmp(left->name,"FLOAT")==0)
        {
            printf("Error type 6 at Line %d: The left-hand side of an assignment must be a varia- ble.\n",p->line);
        }
    }
    //函数调用
    else if(strcmp(p->name,"ID")==0&&strcmp(right->name,"LP")==0)
    {
        struct symbol_node *symbol=in_symbol_table(p,-1);
        if(symbol==NULL)
        {
            printf("Error type 2 at Line %d: Undefined function \"%s\".\n",p->line,p->content);
        }
        else if(symbol->tag!=3)
        {
            printf("Error type 11 at Line %d: \"%s\" is not a function.\n",p->line,p->content);
        }
        else
        {
            //判断参数个数是否正确
            int num=0;
            right=right->right;
            if(strcmp(right->name,"RP")!=0)
            {
                struct ast *arg_p=right->left;
                while(arg_p!=NULL)
                {
                    if(strcmp(arg_p->name,"Exp")==0)
                    {
                        num+=1;
                    }
                    if(strcmp(arg_p->name,"Args")==0)
                    {
                        arg_p=arg_p->left;
                    }
                    else
                    {
                        arg_p=arg_p->right;
                    }
                }
            }
            if(symbol->pnum!=num)
            {
                printf("Error type 9 at Line %d: Function \"%s\" is not applicable for arguments\n",right->line,symbol->name);
            }
        }
    }
    //基本运算
    else if(right!=NULL && (strcmp(right->name,"PLUS")==0||strcmp(right->name,"MINUS")==0||strcmp(right->name,"STAR")==0||strcmp(right->name,"DIV")==0))
    {
        struct ast *right_exp=right->right->left;
        if(strcmp(left->name,"ID")==0)
        {
            struct symbol_node *symbol=in_symbol_table(left,0);
            if(symbol==NULL)
            {
                printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",p->line,left->content);
            }
            else
            {
                if(strcmp(right_exp->name,"ID")==0)
                {
                    struct symbol_node *right_symbol=in_symbol_table(left,0);
                    if(right_symbol==NULL)
                    {
                        printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",p->line,right_exp->content);
                    }
                    else
                    {
                        if(strcmp(symbol->type,right_symbol->type)!=0)
                        {
                            printf("Error type 7 at Line %d: Type mismatched for operands.\n",p->line);
                        }
                    }
                }
                else if(strcmp(right_exp->name,"INT")==0)
                {
                    if(strcmp(symbol->type,"int")!=0)
                    {
                        printf("Error type 7 at Line %d: Type mismatched for operands.\n",p->line);
                    }
                }
                else if(strcmp(right_exp->name,"FLOAT")==0)
                {
                    if(strcmp(symbol->type,"float")!=0)
                    {
                        printf("Error type 7 at Line %d: Type mismatched for operands.\n",p->line);
                    }
                }
            }
        }
        else if(strcmp(left->name,"INT")==0)
        {
            if(strcmp(right_exp->name,"ID")==0)
            {
                struct symbol_node *right_symbol=in_symbol_table(right_exp,0);
                if(right_symbol==NULL)
                {
                    printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",p->line,right_exp->content);
                }
                else
                {
                    if(strcmp("int",right_symbol->type)!=0)
                    {
                        printf("Error type 7 at Line %d: Type mismatched for operands.\n",p->line);
                    }

                }
            }
            else if(strcmp(right_exp->name,"FLOAT")==0)
            {
                printf("Error type 7 at Line %d: Type mismatched for operands.\n",p->line);
            }
        }
        else if(strcmp(left->name,"FLOAT")==0)
        {
            if(strcmp(right_exp->name,"ID")==0)
            {
                struct symbol_node *right_symbol=in_symbol_table(right_exp,0);
                if(right_symbol==NULL)
                {
                    printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",p->line,right_exp->content);
                }
                else
                {
                    if(strcmp("float",right_symbol->type)!=0)
                    {
                        printf("Error type 7 at Line %d: Type mismatched for operands.\n",p->line);
                    }
                }
            }
            else if(strcmp(right_exp->name,"INT")==0)
            {
                printf("Error type 7 at Line %d: Type mismatched for operands.\n",p->line);
            }
        }
    }
    //数组
    else if(strcmp(p->left->name,"ID")==0&&strcmp(right->name,"LB")==0)
    {
        struct symbol_node *symbol=in_symbol_table(p->left,-1);
        if(symbol==NULL)
        {
            printf("Error type 1 at Line %d: Undefined Array \"%s\".\n",p->line,p->left->content);
        }
        else if(symbol->tag!=2)
        {
            printf("Error type 10 at Line %d: \"%s\" is not an array.\n", p->line,p->left->content);
        }
        else
        {
            right=right->right;
            if(strcmp(right->left->name,"FLOAT")==0)
            {
                printf("Error type 12 at Line %d: \"%f\" is not an integer.\n",p->line,right->left->value);
            }
            else if(strcmp(right->left->name,"ID")==0)
            {
                struct symbol_node *symbol_id=in_symbol_table(right->left,-1);
                if(symbol_id==NULL)
                {
                    printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",p->line,right->left->content);
                }
                else if(strcmp(symbol_id->type,"int"))
                {
                    printf("Error type 12 at Line %d: \"%s\" is not an integer.\n",p->line,right->left->content);
                }
            }
        }
    }
    else if(right!=NULL && strcmp(right->name,"DOT")==0)
    {
        //结构体访问
        if(strcmp(p->left->name,"ID")==0)
        {
            struct symbol_node *symbol=in_symbol_table(p->left,-1);
            if(symbol==NULL)
            {
                printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",p->line,p->left->content);
            }
            else if(symbol->tag!=1)
            {
                printf("Error type 13 at Line %d: Illegal use of \".\".\n",p->line);
            }
            else if(strcmp(symbol->type,"int")==0||strcmp(symbol->type,"float")==0)
            {
                printf("Error type 13 at Line %d: Illegal use of \".\".\n",p->line);
            }
            else
            {
                struct symbol_node *struct_symbol_p=symboltable[3]->next;
                while(struct_symbol_p!=NULL)
                {
                    if(strcmp(struct_symbol_p->name,symbol->type)==0)
                    {
                        break;
                    }
                    struct_symbol_p=struct_symbol_p->next;
                }
                if(struct_symbol_p!=NULL)
                {
                    struct_symbol_p=in_struct_symbol_table(right->right,struct_symbol_p->struct_var);
                    if(struct_symbol_p==NULL)
                    {
                        printf("Error type 14 at Line %d: Non-existent field \"%s\".\n",p->line,right->right->content);
                    }
                }
            }
        }
        else
        {
            printf("Error type 13 at Line %d: Illegal use of \".\".\n",p->line);
        }
    }
    p=NULL;
    return p;
}
void parser(struct ast *p)
{
    if(p==NULL||p->line==-1)
        return;
    if(strcmp(p->name,"Specifier")==0)
    {
        p=parser_Specifier(p);
    }
    else if(strcmp(p->name,"LC")==0)
    {
        array_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
        array_tail->next->pre=array_tail;
        array_tail=array_tail->next;
        array_tail->tag=2;
        array_tail->next=NULL;
        strcpy(array_tail->name,"{");

        var_tail->next=(struct symbol_node*)malloc(sizeof(struct symbol_node));
        var_tail->next->pre=var_tail;
        var_tail=var_tail->next;
        var_tail->tag=1;
        var_tail->next=NULL;
        strcpy(var_tail->name,"{");
        p=p->right;
    }
    else if(strcmp(p->name,"RC")==0)
    {
        while (strcmp(var_tail->name,"{")!=0)
        {
            var_tail=var_tail->pre;
            free(var_tail->next);
            var_tail->next=NULL;
        }
        while(strcmp(var_tail->name,"{")==0||var_tail->tag==5)
        {
            var_tail=var_tail->pre;
            free(var_tail->next);
            var_tail->next=NULL;
        }
        while (strcmp(array_tail->name,"{")!=0)
        {
            array_tail=array_tail->pre;
            free(array_tail->next);
            array_tail->next=NULL;
        }
        array_tail=array_tail->pre;
        free(array_tail->next);
        array_tail->next=NULL;
    }
    else if(strcmp(p->name,"RETURN")==0)
    {
        p=parser_RETURN(p);
    }
    else if(strcmp(p->name,"Exp")==0)
    {
        p=parser_Exp(p);
    }
    if(p!=NULL)
    {
        parser(p->left);
        parser(p->right);
    }
}

struct symbol_node* in_symbol_table(struct ast *p,int index)
{
    if(index==-1)
    {
        for(int i=0;i<4;++i)
        {
            struct symbol_node *symbol_p=symboltable[i]->next;
            while(symbol_p!=NULL)
            {
                if(!strcmp(symbol_p->name,p->content))
                {
                    return symbol_p;
                }
                symbol_p=symbol_p->next;
            }
        }
    }
    else
    {
        struct symbol_node *symbol_p;
        switch (index) {
            case 0:
                symbol_p=var_tail;
                while(symbol_p!=NULL)
                {
                    if(strcmp(symbol_p->name,"{")==0)
                    {
                        return NULL;
                    }
                    if(strcmp(symbol_p->name,p->content)==0)
                    {
                        return symbol_p;
                    }
                    symbol_p=symbol_p->pre;
                }
                break;
            case 1:
                symbol_p=array_tail;
                break;
        }
        symbol_p=symboltable[index];
        while(symbol_p!=NULL)
        {
            if(strcmp(symbol_p->name,p->content)==0)
            {
                return symbol_p;
            }
            symbol_p=symbol_p->next;
        }

    }
    return NULL;
}

struct symbol_node * in_struct_symbol_table(struct ast *p,struct symbol_node *struct_symbol)
{
    struct symbol_node *symbol_p=struct_symbol->next;
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

struct symbol_node* lookup(struct symbol_node *symbol_tail,struct ast *ast_p)
{
    struct symbol_node* p=symbol_tail;
    while (p!=NULL)
    {
        if(!strcmp(p->name,ast_p->content))
            return p;
        p=p->pre;
    }
}
