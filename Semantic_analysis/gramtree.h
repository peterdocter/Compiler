#ifndef _GRAMTREE_H

#define _GRAMTREE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

extern int yylineno;
extern char *yytext;
void yyerror(char *msg);
struct ast *root;

struct ast
{
     int line;
     char *name;
     struct ast *left;
     struct ast *right;
     char *content;//yytext值
     char *type;//类型
     union{
         float value;//float 值
         int int_value;
     };
};

struct ast *create_ast(char *name,int num,...);
void eval(struct ast*,int leavel);

#endif
