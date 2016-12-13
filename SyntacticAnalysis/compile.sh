#!/bin/bash
flex src/flex.l
bison -d src/syntax.y
gcc syntax.tab.c -ll -o parser
