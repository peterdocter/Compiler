#!/bin/bash
bison -d  gramtree.y
flex flex.l
gcc  -std=c11 gramtree.tab.c lex.yy.c symboltable.c gramtree.c inter_code.c main.c -o parser
