%{
    #include "syntax.tab.h"
    struct List *List_head=NULL;
    void create_list_node(char *type);
%}
%option yylineno
INT ([1-9][0-9]{0,31})|0|0x[0-9A-F]+|0[0-7]+
FLOAT ([0-9]+\.[0-9]+)|(1\.[0-9]+e-[1-9][0-9]*)
ID [a-zA-Z_][0-9a-zA-Z_]*
SEMI ";"
COMMA ","
ASSIGNOP "="
RELOP ">"|"<"|">="|"<="|"=="|"!="
PLUS "+"
MINUS "-"
STAR "*"
DIV "/"
AND &&
OR "||"
DOT "."
NOT !
TYPE "int"|"float"
LP "("
RP ")"
LB "["
RB "]"
LC "{"
RC "}"
STRUCT "struct"
RETURN "return"
IF "if"
ELSE "else"
WHILE "while"
EMPTY [ \t]+
DES ("//".*?)|("/*"(.|\n)+"*/")
%%

{DES} {printf("Line(%d):注释 ‘%s’\n",yylineno,yytext);}
\n  {}
{STRUCT} {
            yylval.a=create_node("STRUCT",0,yylineno);
            create_list_node("STRUCT");
            return STRUCT;
        }
{RETURN} {
            yylval.a=create_node("RETURN",0,yylineno);
            create_list_node("RETURN");
            return RETURN;}
{IF} {
        yylval.a=create_node("IF",0,yylineno);
        create_list_node("IF");
        return IF;}
{ELSE} {
        yylval.a=create_node("ELSE",0,yylineno);
        create_list_node("ELSE");
        return ELSE;}
{WHILE} {
        yylval.a=create_node("WHILE",0,yylineno);
        create_list_node("WHILE");
        return WHILE;}

{TYPE} {
        yylval.a=create_node("TYPE",0,yylineno);
        create_list_node("TYPE");
        return TYPE;}

{INT} {
        yylval.a=create_node("INT",0,yylineno);
        create_list_node("INT");
        return INT;}
{FLOAT} {
        yylval.a=create_node("FLOAT",0,yylineno);
        create_list_node("FLOAT");
        return FLOAT;}

{ID} {
        yylval.a=create_node("ID",0,yylineno);
        create_list_node("ID");
        return ID;}
{SEMI} {
        yylval.a=create_node("SEMI",0,yylineno);
        create_list_node("SEMI");
        return SEMI;}
{COMMA} {
        yylval.a=create_node("COMMA",0,yylineno);
        create_list_node("COMMA");
        return COMMA;}
{ASSIGNOP} {
        yylval.a=create_node("ASSIGNOP",0,yylineno);
        create_list_node("ASSIGNOP");
        return ASSIGNOP;}
{RELOP} {
        yylval.a=create_node("RELOP",0,yylineno);
        create_list_node("RELOP");
        return RELOP;}
{PLUS} {
        yylval.a=create_node("PLUS",0,yylineno);
        create_list_node("PLUS");
        return PLUS;}
{MINUS} {
        yylval.a=create_node("MINUS",0,yylineno);
        create_list_node("MINUS");
        return MINUS;}
{STAR} {
        yylval.a=create_node("STAR",0,yylineno);
        create_list_node("STAR");
        return STAR;}
{DIV} {
        yylval.a=create_node("DIV",0,yylineno);
        create_list_node("DIV");
        return DIV;}
{AND} {
        yylval.a=create_node("AND",0,yylineno);
        create_list_node("AND");
        return AND;}
{OR} {
        yylval.a=create_node("OR",0,yylineno);
        create_list_node("OR");
        return OR;}
{DOT} {
        yylval.a=create_node("DOT",0,yylineno);
        create_list_node("DOT");
        return DOT;}
{NOT} {
        yylval.a=create_node("NOT",0,yylineno);
        create_list_node("NOT");
        return NOT;}
{LP} {
        yylval.a=create_node("LP",0,yylineno);
        create_list_node("LP");
        return LP;}
{RP} {
        yylval.a=create_node("RP",0,yylineno);
        create_list_node("RP");
        return RP;}
{LB} {
        yylval.a=create_node("LB",0,yylineno);
        create_list_node("LB");
        return LB;}
{RB} {
        yylval.a=create_node("RB",0,yylineno);
        create_list_node("RB");
        return RB;}
{LC} {
        yylval.a=create_node("LC",0,yylineno);
        create_list_node("LC");
        return LC;}
{RC} {
        yylval.a=create_node("RC",0,yylineno);
        create_list_node("RC");
        return RC;}

{EMPTY} {}
. {printf("Error type A at Line %d:Mysterious character \"%s\".\n",yylineno,yytext);}
%%

void create_list_node(char *type)
{
    if(List_head==NULL)
    {
        List_head=(struct List*)malloc(sizeof(struct List));
        List_head->next=NULL;
    }
    struct List *p=List_head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=(struct List*)malloc(sizeof(struct List));
    p=p->next;
    p->next=NULL;
    char *string=(char*)malloc(strlen(yytext)+1);
    strcpy(string,yytext);
    p->type=(char*)malloc(5);
    strcpy(p->type,type);
    p->value=string;
}
