%option c++ noyywrap nodefault

%{
#include "parser.tab.hh"
#include <string>
#include <cstdlib>

// Correct pointer passed from main
extern yy::Parser::semantic_type* yylval_ptr;
%}

%%

"if"            return yy::Parser::token::IF;
"else"          return yy::Parser::token::ELSE;
"while"         return yy::Parser::token::WHILE;
"print"         return yy::Parser::token::PRINT;
"int"           return yy::Parser::token::INT_TYPE;
"string"        return yy::Parser::token::STRING_TYPE;

"and"           return yy::Parser::token::AND;
"or"            return yy::Parser::token::OR;
"not"           return yy::Parser::token::NOT;

"=="            return yy::Parser::token::EQ;
"!="            return yy::Parser::token::NEQ;
"<="            return yy::Parser::token::LE;
">="            return yy::Parser::token::GE;
"<"             return yy::Parser::token::LT;
">"             return yy::Parser::token::GT;
"="             return yy::Parser::token::ASSIGN;

"+"             return yy::Parser::token::PLUS;
"-"             return yy::Parser::token::MINUS;
"*"             return yy::Parser::token::MUL;
"/"             return yy::Parser::token::DIV;

"("             return yy::Parser::token::LPAREN;
")"             return yy::Parser::token::RPAREN;
"{"             return yy::Parser::token::LBRACE;
"}"             return yy::Parser::token::RBRACE;
";"             return yy::Parser::token::SEMICOLON;

[0-9]+ {
    yylval_ptr->emplace<int>(std::stoi(yytext));
    return yy::Parser::token::INT;
}

\"([^\"\\]|\\.)*\" {
    std::string val(yytext);
    yylval_ptr->emplace<std::string>(val.substr(1, val.size() - 2));
    return yy::Parser::token::STRING;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval_ptr->emplace<std::string>(yytext);
    return yy::Parser::token::ID;
}

[ \t\r\n]+    ;    // skip whitespace
"//".*        ;    // skip line comments
"/*"([^*]|\*+[^*/])*"*"+"/" ;  // skip block comments

.             return yy::Parser::token::ERROR;

%%
