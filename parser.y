%require "3.2"
%language "c++"
%define api.parser.class {Parser}
%define api.value.type variant
%define parse.error verbose
%define parse.lac full

%left OR
%left AND
%nonassoc EQ NEQ
%nonassoc LT GT LE GE
%left PLUS MINUS
%left MUL DIV
%right NOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%code requires {
    #include <variant>
    #include <memory>
    #include <string>
    #include "ast.h"
    using ASTPtr = std::shared_ptr<ASTNode>;
}

%code provides {
    int yylex(yy::Parser::semantic_type* yylval);
}

%{
#include "ast.h"
extern ASTPtr ast_root;
void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}
%}

%token <int> INT
%token <std::string> ID STRING
%token IF ELSE WHILE PRINT
%token INT_TYPE STRING_TYPE
%token AND OR NOT
%token EQ NEQ LE GE LT GT
%token ASSIGN
%token PLUS MINUS MUL DIV
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token ERROR

%type <ASTPtr> program stmt stmt_list simple_stmt block_stmt expr

%start program

%%

program:
    stmt_list                         { ast_root = $1; }
;

stmt_list:
    stmt_list stmt                    { $$ = new_stmt_list($1, $2); }
  | stmt                              { $$ = new_stmt_list(nullptr, $1); }
;

stmt:
    simple_stmt
  | block_stmt
;

simple_stmt:
    ID ASSIGN expr SEMICOLON          { $$ = new_assign($1, $3); }
  | INT_TYPE ID SEMICOLON             { $$ = new_decl("int", $2); }
  | STRING_TYPE ID SEMICOLON          { $$ = new_decl("string", $2); }
  | PRINT expr SEMICOLON              { $$ = new_print($2); }
  | IF LPAREN expr RPAREN stmt ELSE stmt
                                       { $$ = new_if_else($3, $5, $7); }
  | IF LPAREN expr RPAREN stmt %prec LOWER_THAN_ELSE
                                       { $$ = new_if($3, $5); }
  | WHILE LPAREN expr RPAREN stmt      { $$ = new_while($3, $5); }
;

block_stmt:
    LBRACE stmt_list RBRACE            { $$ = $2; }
  | error SEMICOLON                    { yyerrok; $$ = nullptr; }
;

expr:
    expr PLUS expr                     { $$ = new_binop("+", $1, $3); }
  | expr MINUS expr                    { $$ = new_binop("-", $1, $3); }
  | expr MUL expr                      { $$ = new_binop("*", $1, $3); }
  | expr DIV expr                      { $$ = new_binop("/", $1, $3); }
  | expr EQ expr                       { $$ = new_binop("==", $1, $3); }
  | expr NEQ expr                      { $$ = new_binop("!=", $1, $3); }
  | expr LT expr                       { $$ = new_binop("<", $1, $3); }
  | expr GT expr                       { $$ = new_binop(">", $1, $3); }
  | expr LE expr                       { $$ = new_binop("<=", $1, $3); }
  | expr GE expr                       { $$ = new_binop(">=", $1, $3); }
  | expr AND expr                      { $$ = new_binop("and", $1, $3); }
  | expr OR expr                       { $$ = new_binop("or", $1, $3); }
  | NOT expr                           { $$ = new_unop("not", $2); }
  | LPAREN expr RPAREN                 { $$ = $2; }
  | ID                                 { $$ = new_var($1); }
  | INT                                { $$ = new_int($1); }
  | STRING                             { $$ = new_string($1); }
;

%%
