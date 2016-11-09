%{
    #include "syntax.tab.h"
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
%%
\n  {}
{STRUCT} {
            yylval.a=create_node("STRUCT",0,yylineno);
            return STRUCT;
        }
{RETURN} {
            yylval.a=create_node("RETURN",0,yylineno);
            return RETURN;}
{IF} {
        yylval.a=create_node("IF",0,yylineno);
        return IF;}
{ELSE} {
        yylval.a=create_node("ELSE",0,yylineno);
        return ELSE;}
{WHILE} {
        yylval.a=create_node("WHILE",0,yylineno);
        return WHILE;}

{TYPE} {
        yylval.a=create_node("TYPE",0,yylineno);
        return TYPE;}

{INT} {
        yylval.a=create_node("INT",0,yylineno);
        return INT;}
{FLOAT} {
        yylval.a=create_node("FLOAT",0,yylineno);
        return FLOAT;}

{ID} {
        yylval.a=create_node("ID",0,yylineno);
        return ID;}
{SEMI} {
        yylval.a=create_node("SEMI",0,yylineno);
        return SEMI;}
{COMMA} {
        yylval.a=create_node("COMMA",0,yylineno);
        return COMMA;}
{ASSIGNOP} {
        yylval.a=create_node("ASSIGNOP",0,yylineno);
        return ASSIGNOP;}
{RELOP} {
        yylval.a=create_node("RELOP",0,yylineno);
        return RELOP;}
{PLUS} {
        yylval.a=create_node("PLUS",0,yylineno);
        return PLUS;}
{MINUS} {
        yylval.a=create_node("MINUS",0,yylineno);
        return MINUS;}
{STAR} {
        yylval.a=create_node("STAR",0,yylineno);
        return STAR;}
{DIV} {
        yylval.a=create_node("DIV",0,yylineno);
        return DIV;}
{AND} {
        yylval.a=create_node("AND",0,yylineno);
        return AND;}
{OR} {
        yylval.a=create_node("OR",0,yylineno);
        return OR;}
{DOT} {
        yylval.a=create_node("DOT",0,yylineno);
        return DOT;}
{NOT} {
        yylval.a=create_node("NOT",0,yylineno);
        return NOT;}
{LP} {
        yylval.a=create_node("LP",0,yylineno);
        return LP;}
{RP} {
        yylval.a=create_node("RP",0,yylineno);
        return RP;}
{LB} {
        yylval.a=create_node("LB",0,yylineno);
        return LB;}
{RB} {
        yylval.a=create_node("RB",0,yylineno);
        return RB;}
{LC} {
        yylval.a=create_node("LC",0,yylineno);
        return LC;}
{RC} {
        yylval.a=create_node("RC",0,yylineno);
        return RC;}

{EMPTY} {}
. {printf("Error type A at Line %d:Mysterious character \"%s\".\n",yylineno,yytext);}
%%
