/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRUCT = 258,
     RETURN = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     TYPE = 263,
     INT = 264,
     FLOAT = 265,
     ID = 266,
     SEMI = 267,
     COMMA = 268,
     ASSIGNOP = 269,
     RELOP = 270,
     PLUS = 271,
     MINUS = 272,
     STAR = 273,
     DIV = 274,
     AND = 275,
     OR = 276,
     DOT = 277,
     NOT = 278,
     LP = 279,
     RP = 280,
     LB = 281,
     RB = 282,
     LC = 283,
     RC = 284
   };
#endif
/* Tokens.  */
#define STRUCT 258
#define RETURN 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define TYPE 263
#define INT 264
#define FLOAT 265
#define ID 266
#define SEMI 267
#define COMMA 268
#define ASSIGNOP 269
#define RELOP 270
#define PLUS 271
#define MINUS 272
#define STAR 273
#define DIV 274
#define AND 275
#define OR 276
#define DOT 277
#define NOT 278
#define LP 279
#define RP 280
#define LB 281
#define RB 282
#define LC 283
#define RC 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "syntax.y"
{
    struct node* a;
}
/* Line 1529 of yacc.c.  */
#line 111 "syntax.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

