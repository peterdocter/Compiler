%{
 #include<stdio.h>
 #include<stdlib.h>
 #include<stdarg.h>
 #include<string.h>
 #define YYDEBUG 1
 struct node
 {
     int line;
     char *name;
     struct node *left;
     struct node *right;
     union
     {
         float float_value;
         int int_value;
         char  *string;
     };
 };

 struct node* create_node(char *name,int num,...);
 void print_tree(struct node *head,int leavel);
%}

%union{
    struct node* a;
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
Program: ExtDefList {$$=create_node("Program",1,$1);print_tree($$,0);}
 ;

ExtDefList: ExtDef ExtDefList {$$=create_node("ExtDefList",2,$1,$2);}
 | {$$=create_node("ExtDefList",0,-1);}
 ;

ExtDef: Specifier ExtDecList SEMI {$$=create_node("ExtDef",3,$1,$2,$3);}
 | Specifier SEMI {$$=create_node("ExtDef",2,$1,$2);}
 | Specifier FunDec CompSt {$$=create_node("ExtDef",3,$1,$2,$3);}
 ;

ExtDecList: VarDec {$$=create_node("ExtDecList",1,$1);}
 | VarDec COMMA ExtDecList {$$=create_node("ExtDecList",3,$1,$2,$3);}
 ;

Specifier:  TYPE {$$=create_node("Specifier",1,$1);}
 | StructSpecifier {$$=create_node("Specifier",1,$1);}
 ;

StructSpecifier: STRUCT OptTag LC DefList RC {$$=create_node("StructSpecifier",5,$1,$2,$3,$4,$5);}
 | STRUCT Tag {$$=create_node("StructSpecifier",2,$1,$2);}
 ;

OptTag: ID {$$=create_node("OptTag",1,$1);}
 |{$$=create_node("OptTag",0,-1);}
 ;

Tag: ID {$$=create_node("Tag",1,$1);}
 ;

VarDec: ID {$$=create_node("VarDec",1,$1);}
 | VarDec LB INT RB {$$=create_node("VarDec",4,$1,$2,$3,$4);}
 | error {yyerror("Miss ]")}
 ;

FunDec: ID LP VarList RP {$$=create_node("FunDec",4,$1,$2,$3,$4);}
 | ID LP RP {$$=create_node("FunDec",3,$1,$2,$3);}
 | error RP {yyerror("Miss )");}
 ;

VarList: ParamDec COMMA VarList {$$=create_node("VarList",3,$1,$2,$3);}
 | ParamDec {$$=create_node("VarList",1,$1);}
 ;

ParamDec: Specifier VarDec {$$=create_node("ParamDec",2,$1,$2);}
 ;

CompSt: LC DefList StmtList RC {$$=create_node("CompSt",4,$1,$2,$3,$4);}
    | error RC {yyerror("Miss }");}
 ;

StmtList: Stmt StmtList {$$=create_node("StmtList",2,$1,$2);}
 | {$$=create_node("StmtList",0,-1);}
 ;

Stmt: Exp SEMI {$$=create_node("Stmt",2,$1,$2);}
 | CompSt {$$=create_node("Stmt",1,$1);}
 | RETURN Exp SEMI {$$=create_node("Stmt",3,$1,$2,$3);}
 | IF LP Exp RP Stmt {$$=create_node("Stmt",5,$1,$2,$3,$4,$5);}
 | IF LP Exp RP Stmt ELSE Stmt {$$=create_node("Stmt",7,$1,$2,$3,$4,$5,$6,$7);}
 | WHILE LP Exp RP Stmt {$$=create_node("Stmt",5,$1,$2,$3,$4,$5);}
 | error SEMI {yyerror("Miss ;");}
 ;

DefList: Def DefList  {$$=create_node("DefList",2,$1,$2);}
 | {$$=create_node("DefList",0,-1);}
 ;

Def: Specifier DecList SEMI {$$=create_node("Def",3,$1,$2,$3);}
 ;

DecList: Dec {$$=create_node("DecList",1,$1);}
 | Dec COMMA DecList {$$=create_node("DecList",3,$1,$2,$3);}
 ;

Dec: VarDec {$$=create_node("Dec",1,$1);}
 | VarDec ASSIGNOP Exp {$$=create_node("Dec",3,$1,$2,$3);}
 ;

Exp: Exp ASSIGNOP Exp {$$=create_node("Exp",3,$1,$2,$3);}
 | Exp AND Exp {$$=create_node("Exp",3,$1,$2,$3);}
 | Exp OR Exp {$$=create_node("Exp",3,$1,$2,$3);}
 | Exp RELOP Exp {$$=create_node("Exp",3,$1,$2,$3);}
 | Exp PLUS Exp {$$=create_node("Exp",3,$1,$2,$3);}
 | Exp MINUS Exp {$$=create_node("Exp",3,$1,$2,$3);}
 | Exp STAR Exp {$$=create_node("Exp",3,$1,$2,$3);}
 | Exp DIV Exp {$$=create_node("Exp",3,$1,$2,$3);}
 | LP Exp RP {$$=create_node("Exp",3,$1,$2,$3);}
 | MINUS Exp {$$=create_node("Exp",2,$1,$2);}
 | NOT Exp {$$=create_node("Exp",2,$1,$2);}
 | ID LP Args RP {$$=create_node("Exp",4,$1,$2,$3,$4);}
 | ID LP RP {$$=create_node("Exp",3,$1,$2,$3);}
 | Exp LB Exp RB  {$$=create_node("Exp",4,$1,$2,$3,$4);}
 | Exp DOT ID {$$=create_node("Exp",3,$1,$2,$3);}
 | ID {$$=create_node("Exp",1,$1);}
 | INT {$$=create_node("Exp",1,$1);}
 | FLOAT {$$=create_node("Exp",1,$1);}
 ;

Args: Exp COMMA Args {$$=create_node("Args",3,$1,$2,$3);}
 | Exp {$$=create_node("Args",1,$1);}
 ;
%%
#include "lex.yy.c"
int main(int argc, char const *argv[])
{
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
    /*
    yyparse();
    return 0;
    */
}
struct node * create_node(char *name,int num,...)
{
    va_list valist;

    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->left=NULL;
    head->right=NULL;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    head->name=name;
    va_start(valist, num);
    if(num>0)
    {
        temp=va_arg(valist, struct node *);
        head->left=temp;
        head->line=temp->line;
        if(num>=2)
        {
            for(int i=0;i<num-1;++i)
            {
                temp->right=va_arg(valist, struct node*);
                temp=temp->right;
            }
        }
    }
    else
    {
        int line=va_arg(valist,int);
        head->line=line;
        if((strcmp(head->name,"ID")==0)||(strcmp(head->name,"TYPE")==0))
        {
            char *string=(char*)malloc(strlen(yytext)+1);
            strcpy(string,yytext);
            head->string=string;
        }
        else if(strcmp(head->name,"INT")==0)
        {
            head->int_value=atoi(yytext);
        }
        else if(strcmp(head->name,"FLOAT")==0)
        {
            head->float_value=atof(yytext);
        }
    }
    return head;
}

void print_tree(struct node *head,int leavel)
{
    if(head!=NULL)
    {
        for(int i=0;i<leavel;++i)
        {
            printf("  ");
        }
        if(head->line!=-1)
        {
            printf("%s",head->name);
            if((strcmp(head->name,"ID")==0)||(strcmp(head->name,"TYPE")==0))
            {
                printf(":%s",head->string);
            }
            else if(strcmp(head->name,"INT")==0)
            {
                printf(":%d ",head->int_value );
            }
            else if(strcmp(head->name,"FLOAT")==0)
            {
                printf(":%f ",head->float_value );
            }
            else{
                printf("(%d)",head->line);
            }
        }
        printf("\n",head->line);
        print_tree(head->left,leavel+1);
        print_tree(head->right,leavel);
    }
}

yyerror(char *msg)
{
    printf("type B at Line %d:%s\n",yylineno,msg);
}
