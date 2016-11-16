%{
    #include "gramtree.h"
    #include "gramtree.tab.h"
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
            yylval.a=create_ast("STRUCT",0,yylineno);
            return STRUCT;
        }
{RETURN} {
            yylval.a=create_ast("RETURN",0,yylineno);
            return RETURN;}
{IF} {
        yylval.a=create_ast("IF",0,yylineno);
        return IF;}
{ELSE} {
        yylval.a=create_ast("ELSE",0,yylineno);
        return ELSE;}
{WHILE} {
        yylval.a=create_ast("WHILE",0,yylineno);
        return WHILE;}

{TYPE} {
        yylval.a=create_ast("TYPE",0,yylineno);
        return TYPE;}

{INT} {
        yylval.a=create_ast("INT",0,yylineno);
        return INT;}
{FLOAT} {
        yylval.a=create_ast("FLOAT",0,yylineno);
        return FLOAT;}

{ID} {
        yylval.a=create_ast("ID",0,yylineno);
        return ID;}
{SEMI} {
        yylval.a=create_ast("SEMI",0,yylineno);
        return SEMI;}
{COMMA} {
        yylval.a=create_ast("COMMA",0,yylineno);
        return COMMA;}
{ASSIGNOP} {
        yylval.a=create_ast("ASSIGNOP",0,yylineno);
        return ASSIGNOP;}
{RELOP} {
        yylval.a=create_ast("RELOP",0,yylineno);
        return RELOP;}
{PLUS} {
        yylval.a=create_ast("PLUS",0,yylineno);
        return PLUS;}
{MINUS} {
        yylval.a=create_ast("MINUS",0,yylineno);
        return MINUS;}
{STAR} {
        yylval.a=create_ast("STAR",0,yylineno);
        return STAR;}
{DIV} {
        yylval.a=create_ast("DIV",0,yylineno);
        return DIV;}
{AND} {
        yylval.a=create_ast("AND",0,yylineno);
        return AND;}
{OR} {
        yylval.a=create_ast("OR",0,yylineno);
        return OR;}
{DOT} {
        yylval.a=create_ast("DOT",0,yylineno);
        return DOT;}
{NOT} {
        yylval.a=create_ast("NOT",0,yylineno);
        return NOT;}
{LP} {
        yylval.a=create_ast("LP",0,yylineno);
        return LP;}
{RP} {
        yylval.a=create_ast("RP",0,yylineno);
        return RP;}
{LB} {
        yylval.a=create_ast("LB",0,yylineno);
        return LB;}
{RB} {
        yylval.a=create_ast("RB",0,yylineno);
        return RB;}
{LC} {
        yylval.a=create_ast("LC",0,yylineno);
        return LC;}
{RC} {
        yylval.a=create_ast("RC",0,yylineno);
        return RC;}

{EMPTY} {}
. {printf("Error type A at Line %d:Mysterious character \"%s\".\n",yylineno,yytext);}
%%
int yywrap()
{
    return 1;
}
