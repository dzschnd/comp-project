%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
void yyerror(const char* s);
%}

%union {
    int intval;
    char* strval;
    struct ASTNode* ast;
}

%token <intval> INT
%token <strval> ID STRING
%token IF ELSE WHILE PRINT
%token INT_TYPE STRING_TYPE
%token AND OR NOT
%token EQ NEQ LE GE LT GT
%token ASSIGN
%token PLUS MINUS MUL DIV
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token ERROR

%type <ast> program stmt stmt_list expr

%start program

%%

program:
    stmt_list
;

stmt_list:
    stmt_list stmt      { $$ = new_stmt_list($1, $2); }
  | stmt                { $$ = new_stmt_list(NULL, $1); }
;

stmt:
    ID ASSIGN expr SEMICOLON  { $$ = new_assign($1, $3); }
  | PRINT expr SEMICOLON      { $$ = new_print($2); }
  | IF LPAREN expr RPAREN stmt ELSE stmt  { $$ = new_if_else($3, $5, $7); }
  | IF LPAREN expr RPAREN stmt            { $$ = new_if($3, $5); }
  | WHILE LPAREN expr RPAREN stmt         { $$ = new_while($3, $5); }
  | LBRACE stmt_list RBRACE               { $$ = $2; }
;

expr:
    expr PLUS expr     { $$ = new_binop("+", $1, $3); }
  | expr MINUS expr    { $$ = new_binop("-", $1, $3); }
  | expr MUL expr      { $$ = new_binop("*", $1, $3); }
  | expr DIV expr      { $$ = new_binop("/", $1, $3); }
  | expr EQ expr       { $$ = new_binop("==", $1, $3); }
  | expr NEQ expr      { $$ = new_binop("!=", $1, $3); }
  | expr LT expr       { $$ = new_binop("<", $1, $3); }
  | expr GT expr       { $$ = new_binop(">", $1, $3); }
  | expr LE expr       { $$ = new_binop("<=", $1, $3); }
  | expr GE expr       { $$ = new_binop(">=", $1, $3); }
  | expr AND expr      { $$ = new_binop("and", $1, $3); }
  | expr OR expr       { $$ = new_binop("or", $1, $3); }
  | NOT expr           { $$ = new_unop("not", $2); }
  | LPAREN expr RPAREN { $$ = $2; }
  | ID                 { $$ = new_var($1); }
  | INT             { $$ = new_int($1); }
  | STRING             { $$ = new_string($1); }
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}
