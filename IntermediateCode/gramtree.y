%{
 #include<stdlib.h>
 #include<stdarg.h>
 #include<string.h>
 #include "gramtree.h"
 #include<stdio.h>
 //#define YYDEBUG 1
 #define YYERROR_VERBOSE 1
extern struct ast *root;
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
Program: ExtDefList {root=create_ast("Program",1,$1);}
 ;

ExtDefList: ExtDef ExtDefList {$$=create_ast("ExtDefList",2,$1,$2);}
 | {$$=create_ast("ExtDefList",0,-1);}
 ;

ExtDef: Specifier ExtDecList SEMI {//变量定义
        $$=create_ast("ExtDef",3,$1,$2,$3);
    }
 | Specifier SEMI {$$=create_ast("ExtDef",2,$1,$2);}
 | Specifier FunDec CompSt {//函数定义
        $$=create_ast("ExtDef",3,$1,$2,$3);
   }
 | Specifier FunDec SEMI{
        $$=create_ast("ExtDef",3,$1,$2,$3);
   }
 ;

ExtDecList: VarDec {$$=create_ast("ExtDecList",1,$1);}
 | VarDec COMMA ExtDecList {$$=create_ast("ExtDecList",3,$1,$2,$3);}
 ;

Specifier:  TYPE {
        $$=create_ast("Specifier",1,$1);
        $$->type=(char *)malloc(4);
        strcpy($$->type,$1->content);
    }
 | StructSpecifier {
        $$=create_ast("Specifier",1,$1);
        $$->type=(char *)malloc(sizeof($1->type)+1);
        strcpy($$->type,$1->type);
    }
 ;

StructSpecifier: STRUCT OptTag LC DefList RC {//结构体定义
        $$=create_ast("StructSpecifier",5,$1,$2,$3,$4,$5);
        $$->type=(char *)malloc(sizeof($2->content)+1);
        $$->content=(char *)malloc(sizeof($2->content)+1);
        strcpy($$->content,$2->content);
        strcpy($$->type,$2->content);
    }
 | STRUCT Tag {//结构体
        $$=create_ast("StructSpecifier",2,$1,$2);
        $$->type=(char *)malloc(sizeof($2->content)+1);
        $$->content=(char *)malloc(sizeof($2->content)+1);
        strcpy($$->content,$2->content);
        strcpy($$->type,$2->content);
    }
 ;

OptTag: ID {
        $$=create_ast("OptTag",1,$1);
        $$->content=(char *)malloc(sizeof($1->content)+1);
        strcpy($$->content,$1->content);
    }
 |{$$=create_ast("OptTag",0,-1);}
 ;

Tag: ID {
        $$=create_ast("Tag",1,$1);
        $$->content=(char *)malloc(sizeof($1->content)+1);
        strcpy($$->content,$1->content);
    }
 ;

VarDec: ID {
        $$=create_ast("VarDec",1,$1);
        $$->content=(char *)malloc(sizeof($1->content)+1);
        strcpy($$->content,$1->content);
    }
 | VarDec LB INT RB {
        $$=create_ast("VarDec",4,$1,$2,$3,$4);
        $$->content=(char *)malloc(sizeof($1->content)+1);
        strcpy($$->content,$1->content);
    }
 | error RB{}
 ;

FunDec: ID LP VarList RP {//函数定义
        $$=create_ast("FunDec",4,$1,$2,$3,$4);
        $$->content=$1->content;
    }
 | ID LP RP {//函数定义
        $$=create_ast("FunDec",3,$1,$2,$3);
        $$->content=$1->content;
    }
 | error RP{}
 ;

VarList: ParamDec COMMA VarList {$$=create_ast("VarList",3,$1,$2,$3);}
 | ParamDec {
        $$=create_ast("VarList",1,$1);
    }
 ;

ParamDec: Specifier VarDec {
        $$=create_ast("ParamDec",2,$1,$2);
    }
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
    }
 ;

DecList: Dec {$$=create_ast("DecList",1,$1);}
 | Dec COMMA DecList {
        $$=create_ast("DecList",3,$1,$2,$3);
    }
 ;

Dec: VarDec {$$=create_ast("Dec",1,$1);}
 | VarDec ASSIGNOP Exp {
        $$=create_ast("Dec",3,$1,$2,$3);
        $$->content=$1->content;
    }
 ;

Exp: Exp ASSIGNOP Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
    }
 | Exp AND Exp {$$=create_ast("Exp",3,$1,$2,$3);}
 | Exp OR Exp {$$=create_ast("Exp",3,$1,$2,$3);}
 | Exp RELOP Exp {$$=create_ast("Exp",3,$1,$2,$3);}
 | Exp PLUS Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
    }
 | Exp MINUS Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
    }
 | Exp STAR Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
    }
 | Exp DIV Exp {
        $$=create_ast("Exp",3,$1,$2,$3);
    }
 | LP Exp RP {$$=create_ast("Exp",3,$1,$2,$3);}
 | MINUS Exp {$$=create_ast("Exp",2,$1,$2);}
 | NOT Exp {$$=create_ast("Exp",2,$1,$2);}
 | ID LP Args RP {
        $$=create_ast("Exp",4,$1,$2,$3,$4);
    }
 | ID LP RP {
        $$=create_ast("Exp",3,$1,$2,$3);
    }
 | Exp LB Exp RB {
        $$=create_ast("Exp",4,$1,$2,$3,$4);
    }
 | Exp DOT ID {
        $$=create_ast("Exp",3,$1,$2,$3);
    }
 | ID {
        $$=create_ast("Exp",1,$1);
    }
 | INT {
        $$=create_ast("Exp",1,$1);
        $$->type=(char*)malloc(strlen("int")+1);
        $$->int_value=$$->int_value;
        strcpy($$->type,"int");
    }
 | FLOAT {
        $$=create_ast("Exp",1,$1);
        $$->value=$1->value;
        $$->type=(char*)malloc(strlen("float")+1);
        strcpy($$->type,"float");
    }
 ;

Args: Exp COMMA Args {
        $$=create_ast("Args",3,$1,$2,$3);
    }
 | Exp {
     $$=create_ast("Args",1,$1);
 }
 ;
%%
