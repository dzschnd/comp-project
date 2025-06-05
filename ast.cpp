#include "ast.h"

ASTPtr new_int(int value) {
    return std::make_shared<IntNode>(value);
}

ASTPtr new_string(const std::string& val) {
    return std::make_shared<StringNode>(val);
}

ASTPtr new_var(const std::string& name) {
    return std::make_shared<VarNode>(name);
}

ASTPtr new_binop(const std::string& op, ASTPtr left, ASTPtr right) {
    return std::make_shared<BinOpNode>(op, left, right);
}

ASTPtr new_unop(const std::string& op, ASTPtr expr) {
    return std::make_shared<UnOpNode>(op, expr);
}

ASTPtr new_assign(const std::string& name, ASTPtr expr) {
    return std::make_shared<AssignNode>(name, expr);
}

ASTPtr new_print(ASTPtr expr) {
    return std::make_shared<PrintNode>(expr);
}

ASTPtr new_if(ASTPtr cond, ASTPtr then_branch) {
    return std::make_shared<IfNode>(cond, then_branch);
}

ASTPtr new_if_else(ASTPtr cond, ASTPtr then_branch, ASTPtr else_branch) {
    return std::make_shared<IfElseNode>(cond, then_branch, else_branch);
}

ASTPtr new_while(ASTPtr cond, ASTPtr body) {
    return std::make_shared<WhileNode>(cond, body);
}

ASTPtr new_stmt_list(ASTPtr first, ASTPtr second) {
    return std::make_shared<StmtListNode>(first, second);
}

ASTPtr new_decl(const std::string& type, const std::string& name) {
    return std::make_shared<DeclNode>(type, name);
}