#!/bin/bash
bison -d  syntax.y
flex flex.l
gcc syntax.tab.c lex.yy.c gramtree.c -o parser
