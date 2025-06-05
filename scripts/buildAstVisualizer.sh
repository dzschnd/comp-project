#!/bin/bash

rm mycompiler parser.tab.* lex.yy.cc stack.hh
bison -d -o parser.tab.cc parser.y
flex -o lex.yy.cc lexer.l
g++ main.cpp ast.cpp parser.tab.cc lex.yy.cc -o mycompiler -std=c++17