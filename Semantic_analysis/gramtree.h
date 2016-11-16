extern int yylineno;
extern char *yytext;
void yyerror(char *msg);

struct ast
{
     int line;
     char *name;
     struct ast *left;
     struct ast *right;
     int tag;////1为变量，2为函数，3为常数,4为数组，5为结构体
     char *content;//yytext值
     char *type;//类型
     float value;//float 值
     int int_value;
};

struct var//变量符号表节点
{
    char *name;
    char *type;
    struct var *next;
}*varhead,*vartail;

struct func
{
    int tag;
    char *name;
    char *type;
    char *rtype;
    int pnum;
    struct func *next;
}*funchead,*functail;

struct array
{
    char *name;
    char *type;
    struct array *next;
}*arrayhead,*arraytail;

struct struc
{
    char *name;
    char *type;
    struct struc *next;
}*struchead,*structail;

struct ast *create_ast(char *name,int num,...);
void eval(struct ast*,int leavel);

void newvar(int num,...);
int existvar(struct ast *p);
char *typevar(struct ast *p);


void newfunc(int num,...);
int existfunc(struct ast *p);
char *typefunc(struct ast *p);
int pnumfunc(struct ast *p);

void newarray(int num,...);
int existarray(struct ast *p);
char *typearray(struct ast *p);

void newstruc(int num,...);
int existstuc(struct ast *p);
