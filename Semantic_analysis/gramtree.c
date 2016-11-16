#include "gramtree.h"
# include<stdio.h>
# include<stdlib.h>
# include<stdarg.h>
int rpnum=0;

struct ast *create_ast(char *name,int num,...)
{
    va_list valist;
    struct ast *head=(struct ast *)malloc(sizeof(struct ast));
    if (!head)
    {
        printf("Out of space\n");
        exit(0);
    }
    head->left=NULL;
    head->right=NULL;
    struct ast *temp=NULL;
    head->name=name;
    va_start(valist, num);
    if(num>0)
    {
        temp=va_arg(valist,struct ast*);
        head->left=temp;
        head->line=temp->line;
        if(num==1)
        {
            head->content=temp->content;
            head->tag=temp->tag;
        }
        else
        {
            for(int i=1;i<num;++i)
            {
                temp->right=va_arg(valist,struct ast *);
                temp=temp->right;
            }
        }
    }
    else
    {
        int line=va_arg(valist,int);
        head->line=line;
        if(strcmp(head->name,"INT")==0)
        {
            int value;
            if(strlen(yytext)>1&&yytext[0]=='0'&&yytext[1]!='x')
            {
                sscanf(yytext,"%o",&value);
            }
            else if(strlen(yytext)>1&&yytext[1]=='x')
            {
                sscanf(yytext,"%X",&value);
            }
            else
                value=atoi(yytext);
            head->int_value=value;
        }
        else if(strcmp(head->name,"FLOAT")==0)
        {
            head->value=atof(yytext);
        }
        else
        {
            char *string=(char*)malloc(strlen(yytext)+1);
            strcpy(string,yytext);
            head->content=string;
        }
    }
    return head;
}

void eval(struct ast *head,int leavel)
{
    if(head!=NULL)
    {
        if(head->line!=-1)
        {
            for(int i=0;i<leavel;++i)
            {
                printf("  ");
            }
            printf("%s",head->name);
            if((strcmp(head->name,"ID")==0)||(strcmp(head->name,"TYPE")==0))
            {
                printf(":%s",head->content);
            }
            else if(strcmp(head->name,"INT")==0)
            {
                printf(":%d ",head->int_value);
            }
            else if(strcmp(head->name,"FLOAT")==0)
            {
                printf(":%f ",head->value);
            }
            else
            {
                printf("(%d)",head->line);
            }
            printf("\n");
        }
        eval(head->left,leavel+1);
        eval(head->right,leavel);
    }
}

void newvar(int num,...)//建立变量符号表
{
    va_list valist;
    struct var *p=(struct var *)malloc(sizeof(struct var));
    p->next=NULL;
    struct ast *temp;
    va_start(valist, num);
    temp=va_arg(valist, struct ast *);
    p->type=temp->content;
    temp=va_arg(valist, struct ast *);
    p->name=temp->content;
    vartail->next=p;
    vartail=p;
}

int existvar(struct ast *p)
{
    struct var *var_p=varhead->next;
    while(var_p!=NULL)
    {
        if(strcmp(var_p->name,p->content)==0)
        {
            return 1;
        }
        var_p=var_p->next;
    }
    return 0;
}

char * typevar(struct ast *p)
{
    struct var *var_p=varhead->next;
    while(var_p!=NULL)
    {
        if(strcmp(var_p->name,p->content)==0)
        {
            return var_p->type;
        }
        var_p=var_p->next;
    }
}

void newfunc(int num,...)
{
    va_list valist;
    struct ast *temp;
    va_start(valist, num);
    switch (num) {
        case 1:
            functail->pnum+=1;
            break;
        case 2://记录函数名
            temp=va_arg(valist,struct ast *);
            functail->name=temp->content;
            break;
        case 3://记录返回值类型
            temp=va_arg(valist,struct ast *);
            functail->rtype=temp->type;
            break;
        default:
            rpnum=0;
            temp=va_arg(valist,struct ast *);
            if(functail->rtype!=NULL)
            {
                if(strcmp(functail->rtype,temp->content))
                {
                    printf("Error type 8 at Line %d:Type mismatched for return.\n",yylineno);
                }
            }
            functail->type=temp->type;
            functail->tag=1;
            struct func *a=(struct func*)malloc(sizeof(struct func));
            a->name=NULL;
            a->next=NULL;
            functail->next=a;
            functail=a;
            break;
    }
}

int existfunc(struct ast *p)
{
    struct func *func_p;
    func_p=funchead->next;
    while(func_p!=NULL&&func_p->name!=NULL&&func_p->tag==1)
    {
        if(strcmp(func_p->name,p->content)==0)
        {
            return 1;
        }
        func_p=func_p->next;
    }
    return 0;
}

char * typefunc(struct ast *p)
{
    struct func* func_p=funchead->next;
    while(func_p!=NULL)
    {
        if(strcmp(func_p->name,p->content)==0)
        {
            return func_p->type;
        }
        func_p=func_p->next;
    }
}

int pnumfunc(struct ast *p)
{
    struct func* func_p=funchead->next;
    while(func_p!=NULL)
    {
        if(strcmp(func_p->name,p->content)==0)
        {
            return func_p->pnum;
        }
        func_p=func_p->next;
    }
}


void newarray(int num,...)
{
    va_list valist;
    struct array *p=(struct array*)malloc(sizeof(struct array));
    p->next=NULL;
    struct ast *temp;
    va_start(valist, num);
    temp=va_arg(valist,struct ast*);
    p->type=temp->content;
    temp=va_arg(valist,struct ast*);
    p->name=temp->content;
    arraytail->next=p;
    arraytail=p;
}

int existarray(struct ast *p)
{
    struct array *array_p=arrayhead->next;
    while(array_p!=NULL)
    {
        if(strcmp(array_p->name,p->content)==0)
        {
            return 1;
        }
        array_p=array_p->next;
    }
    return 0;
}

char * typearray(struct ast *p)
{
    struct array *array_p=arrayhead->next;
    while(array_p!=NULL)
    {
        if(strcmp(array_p->name,p->content)==0)
        {
            return array_p->type;
        }
        array_p=array_p->next;
    }
}

void newstruc(int num,...)
{
    va_list valist;
    struct struc *p=(struct struc *)malloc(sizeof(struct struc));
    p->next=NULL;
    struct ast *temp;
    va_start(valist, num);
    temp=va_arg(valist,struct ast*);
    p->name=temp->content;
    structail->next=p;
    structail=p;
}

int existstuc(struct ast *p)
{
    struct struc *struc_p=struchead->next;
    while(struc_p!=NULL)
    {
        if(strcmp(struc_p->name,p->content)==0)
        {
            return 1;
        }
        struc_p=struc_p->next;
    }
    return 0;
}

void yyerror(char *msg)
{
    printf("type B at Line %d:%s\n",yylineno,msg);
}


int main(int argc, char const *argv[])
{
    varhead=(struct var*)malloc(sizeof(struct var));
    varhead->next=NULL;
    vartail=varhead;

    funchead=(struct func*)malloc(sizeof(struct func));
    functail=(struct func*)malloc(sizeof(struct func));
    functail->next=NULL;
    funchead->next=functail;
    functail->pnum=0;

    arrayhead=(struct array*)malloc(sizeof(struct array));
    arrayhead->next=NULL;
    arraytail=arrayhead;

    struchead=(struct struc *)malloc(sizeof(struct struc));
    struchead->next=NULL;
    structail=struchead;

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
        return 0;
    }
    yyparse();
    return 0;
}
