%{
 #include<stdlib.h>
 #include<stdarg.h>
 #include<string.h>
 #include "gramtree.h"
 #include<stdio.h>
 //#define YYDEBUG 1
 #define YYERROR_VERBOSE 1
 extern int rpnum;

FILE* file;
%}

%union{
    struct ast* a;
}

%token <a> STRUCT RETURN  IF  ELSE WHILE TYPE INT FLOAT ID  SEMI COMMA ASSIGNOP RELOP
%token <a>  PLUS MINUS STAR DIV AND OR  DOT NOT LP  RP  LB  RB  LC  RC

%type <a> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier OptTag  Tag VarDec  FunDec VarList ParamDec CompSt StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT

%%
Program: ExtDefList {$$=create_ast("Program",1,$1);}
 ;

ExtDefList: ExtDef ExtDefList {$$=create_ast("ExtDefList",2,$1,$2);}
 | {$$=create_ast("ExtDefList",0,-1);}
 ;

ExtDef: Specifier ExtDecList SEMI {//变量定义:检查是否重定义Error type 3
        $$=create_ast("ExtDef",3,$1,$2,$3);
        if(existvar($2))
        {
            printf("Error type 3 at Line %d:Redefined Variable '%s'\n",yylineno,$2->content);
        }
        else{
            newvar(2,$1,$2);
        }
    }
 | Specifier SEMI {$$=create_ast("ExtDef",2,$1,$2);}
 | Specifier FunDec CompSt {//函数定义
        $$=create_ast("ExtDef",3,$1,$2,$3);
        newfunc(4,$1);
   }
 ;

ExtDecList: VarDec {$$=create_ast("ExtDecList",1,$1);}
 | VarDec COMMA ExtDecList {$$=create_ast("ExtDecList",3,$1,$2,$3);}
 ;

Specifier:  TYPE {$$=create_ast("Specifier",1,$1);}
 | StructSpecifier {$$=create_ast("Specifier",1,$1);}
 ;

StructSpecifier: STRUCT OptTag LC DefList RC {//结构体定义
        $$=create_ast("StructSpecifier",5,$1,$2,$3,$4,$5);
        if(existstuc($2))
        {
            printf("Error type 16 at Line %d:Duplicated name '%s'\n",yylineno,$2->content);
        }
        else{
            newstruc(1,$2);
        }
    }
 | STRUCT Tag {//结构体
        $$=create_ast("StructSpecifier",2,$1,$2);
        if(!existstuc($2))
        {
            printf("Error type 17 at Line %d:undefined structure '%s'\n",yylineno,$2->content);
        }
    }
 ;

OptTag: ID {$$=create_ast("OptTag",1,$1);}
 |{$$=create_ast("OptTag",0,-1);}
 ;

Tag: ID {$$=create_ast("Tag",1,$1);}
 ;

VarDec: ID {$$=create_ast("VarDec",1,$1);}
 | VarDec LB INT RB {$$=create_ast("VarDec",4,$1,$2,$3,$4);}
 | error RB{}
 ;

FunDec: ID LP VarList RP {//函数定义
        $$=create_ast("FunDec",4,$1,$2,$3,$4);
        if(existfunc($1))
        {
            printf("Error type 4 at Line %d:Redefined Function '%s'\n",yylineno,$1->content);
        }
        else{
            newfunc(2,$1);
        }
    }
 | ID LP RP {//函数定义
        $$=create_ast("FunDec",3,$1,$2,$3);
        if(existfunc($1))
        {
            printf("Error type 4 at Line %d:Redefined Function '%s'\n",yylineno,$1->content);
        }
        else{
            newfunc(2,$1);
        }
    }
 | error RP{}
 ;

VarList: ParamDec COMMA VarList {$$=create_ast("VarList",3,$1,$2,$3);}
 | ParamDec {$$=create_ast("VarList",1,$1);}
 ;

ParamDec: Specifier VarDec {$$=create_ast("ParamDec",2,$1,$2);}
 ;

CompSt: LC DefList StmtList RC {$$=create_ast("CompSt",4,$1,$2,$3,$4);}
 ;

StmtList: Stmt StmtList {$$=create_ast("StmtList",2,$1,$2);}
 | {$$=create_ast("StmtList",0,-1);}
 ;

Stmt: Exp SEMI {$$=create_ast("Stmt",2,$1,$2);}
 | CompSt {$$=create_ast("Stmt",1,$1);}
 | RETURN Exp SEMI {$$=create_ast("Stmt",3,$1,$2,$3);}
 | IF LP Exp RP Stmt {$$=create_ast("Stmt",5,$1,$2,$3,$4,$5);}
 | IF LP Exp RP Stmt ELSE Stmt {$$=create_ast("Stmt",7,$1,$2,$3,$4,$5,$6,$7);}
 | WHILE LP Exp RP Stmt {$$=create_ast("Stmt",5,$1,$2,$3,$4,$5);}
 | error SEMI{}
 ;

DefList: Def DefList  {$$=create_ast("DefList",2,$1,$2);}
 | {$$=create_ast("DefList",0,-1);}
 ;

Def: Specifier DecList SEMI {
        $$=create_ast("Def",3,$1,$2,$3);
        if(existvar($2))
        {
            printf("Error type 3 at Line %d:Redefined Variable '%s'\n",yylineno,$2->content);
        }
        else if($2->tag==4){
            newarray(2,$1,$2);
        }
        else{
            newvar(2,$1,$2);
        }
    }
 ;

DecList: Dec {$$=create_ast("DecList",1,$1);}
 | Dec COMMA DecList {$$=create_ast("DecList",3,$1,$2,$3);$$->tag=$3->tag;}
 ;

Dec: VarDec {$$=create_ast("Dec",1,$1);}
 | VarDec ASSIGNOP Exp {$$=create_ast("Dec",3,$1,$2,$3);$$->content=$1->content;}
 ;

Exp: Exp ASSIGNOP Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))
        {
            printf("Error type 5 at Line %d:Type mismatched for assignment.\n",yylineno);
            $$->type=(char *)malloc(sizeof(10));
            strcpy($$->type,"undefined");
        }
        else{
            $$->type=$1->type;
        }
    }
 | Exp AND Exp {$$=create_ast("Exp",3,$1,$2,$3);}
 | Exp OR Exp {$$=create_ast("Exp",3,$1,$2,$3);}
 | Exp RELOP Exp {$$=create_ast("Exp",3,$1,$2,$3);}
 | Exp PLUS Exp {//检查类型是否匹配
        $$=create_ast("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))
        {
            printf("Error type 7 at Line %d:Type mismatched for operand.\n",yylineno);
            $$->type=(char *)malloc(sizeof(10));
            strcpy($$->type,"undefined");
        }
        else
        {
            $$->type=$1->type;
        }
    }
 | Exp MINUS Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))
        {
            printf("Error type 7 at Line %d:Type mismatched for operand.\n",yylineno);
        }
    }
 | Exp STAR Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))
        {
            printf("Error type 7 at Line %d:Type mismatched for operand.\n",yylineno);
        }
    }
 | Exp DIV Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
        if(strcmp($1->type,$3->type))
        {
            printf("Error type 7 at Line %d:Type mismatched for operand.\n",yylineno);
        }
    }
 | LP Exp RP {$$=create_ast("Exp",3,$1,$2,$3);}
 | MINUS Exp {$$=create_ast("Exp",2,$1,$2);}
 | NOT Exp {$$=create_ast("Exp",2,$1,$2);}
 | ID LP Args RP {//检查函数是否定义
        $$=create_ast("Exp",4,$1,$2,$3,$4);
        if(!existfunc($1))
        {
            printf("Error type 2 at Line %d:undefined Function %s\n",yylineno,$1->content);
        }
    }
 | ID LP RP {$$=create_ast("Exp",3,$1,$2,$3);}
 | Exp LB Exp RB {
        $$=create_ast("Exp",4,$1,$2,$3,$4);
        if(strcmp($3->type,'int'))
        {
            printf("Error type 12 at Line %d:%s is not a integer.\n",yylineno,$3->content);
        }
        else if((!existarray($1))&&(existvar($1)||existfunc($1)))
        {
            printf("Error type 10 at Line %d:'%s'is not an array.\n",yylineno,$1->content);
        }
        else if(!existarray($1))
        {
            printf("Error type 2 at Line %d:undefined Array %s\n",yylineno,$1->content);
        }
    }
 | Exp DOT ID {
        $$=create_ast("Exp",3,$1,$2,$3);
        if(!existstuc($1))
        {
            printf("Error type 13 at Line %d:Illegal use of '.'.\n",yylineno);
        }
    }
 | ID {
        $$=create_ast("Exp",1,$1);
        if(!existvar($1)&&!existarray($1))
        {
            printf("Error type 1 at Line %d:undefined variable %s\n",yylineno,$1->content);
            $$->type=(char *)malloc(sizeof(10));
            strcpy($$->type,"undefined");
        }
        else{
            $$->type=typevar($1);
        }
    }
 | INT {
        $$=create_ast("Exp",1,$1);
        $$->tag=3;
        $$->type=(char*)malloc(strlen("int")+1);
        $$->int_value=$$->int_value;
        strcpy($$->type,"int");
    }
 | FLOAT {
        $$=create_ast("Exp",1,$1);
        $$->tag=3;
        $$->value=$1->value;
        $$->type=(char*)malloc(strlen("float")+1);
        strcpy($$->type,"float");
    }
 | error{yyerrok;}
 ;

Args: Exp COMMA Args {
        $$=create_ast("Args",3,$1,$2,$3);
        rpnum+=1;
    }
 | Exp {
     $$=create_ast("Args",1,$1);
     rpnum+=1;
 }
 ;
%%
