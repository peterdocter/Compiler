#include "gramtree.h"

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

void yyerror(char *msg)
{
    printf("Error type B at Line %d:%s\n",yylineno,msg);
}
