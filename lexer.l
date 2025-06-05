%{
#include "parser.tab.h"
#include <string.h>
%}

%%
"if"        return IF;
"else"      return ELSE;
"while"     return WHILE;
"print"     return PRINT;
"int"       return INT_TYPE;
"string"    return STRING_TYPE;

"and"       return AND;
"or"        return OR;
"not"       return NOT;

"=="        return EQ;
"!="        return NEQ;
"<="        return LE;
">="        return GE;
"<"         return LT;
">"         return GT;
"="         return ASSIGN;

"+"         return PLUS;
"-"         return MINUS;
"*"         return MUL;
"/"         return DIV;

"("         return LPAREN;
")"         return RPAREN;
"{"         return LBRACE;
"}"         return RBRACE;
";"         return SEMICOLON;

[0-9]+      { yylval.intval = atoi(yytext); return INT; }
\"([^\\\"]|\\.)*\" { yylval.strval = strdup(yytext); return STRING; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.strval = strdup(yytext); return ID; }

[ \t\r\n]+  ; // пропуск пробелов

"//".*      ; // однострочный комментарий
"/*"([^*]|\*+[^*/])*\*+"/" ; // многострочный комментарий

.           { printf("Unknown character: %s\n", yytext); return ERROR; }

%%
