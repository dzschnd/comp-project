#include <fstream>
#include <iostream>
#include <memory>
#include "parser.tab.hh"
#include <FlexLexer.h>

#include "ast.h"

ASTPtr ast_root;

yyFlexLexer lexer;
yy::Parser::semantic_type* yylval_ptr = nullptr;

int yylex(yy::Parser::semantic_type* lval) {
    yylval_ptr = lval;
    return lexer.yylex();
}

namespace yy {
    void Parser::error(const std::string& msg) {
        std::cerr << "Parser error: " << msg << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./compiler <source.mc>" << std::endl;
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Could not open input file: " << argv[1] << std::endl;
        return 1;
    }

    lexer.switch_streams(&in, nullptr); // set input

    yy::Parser parser;
    parser.parse();

    if (ast_root)
        ast_root->print();
    else
        std::cerr << "No AST generated.\n";

    return 0;
}
