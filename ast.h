#ifndef AST_H
#define AST_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

using ASTPtr = std::shared_ptr<ASTNode>;

inline void print_indent(int indent) {
    for (int i = 0; i < indent; ++i)
        std::cout << "  ";
}

// Integer literal
class IntNode : public ASTNode {
public:
    int value;
    IntNode(int val) : value(val) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Int(" << value << ")\n";
    }
};

// String literal
class StringNode : public ASTNode {
public:
    std::string value;
    StringNode(const std::string& val) : value(val) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "String(\"" << value << "\")\n";
    }
};

// Variable
class VarNode : public ASTNode {
public:
    std::string name;
    VarNode(const std::string& n) : name(n) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Var(" << name << ")\n";
    }
};

// Binary operation
class BinOpNode : public ASTNode {
public:
    std::string op;
    ASTPtr left, right;
    BinOpNode(const std::string& o, ASTPtr l, ASTPtr r)
        : op(o), left(l), right(r) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "BinOp(" << op << ")\n";
        left->print(indent + 1);
        right->print(indent + 1);
    }
};

// Unary operation
class UnOpNode : public ASTNode {
public:
    std::string op;
    ASTPtr expr;
    UnOpNode(const std::string& o, ASTPtr e)
        : op(o), expr(e) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "UnOp(" << op << ")\n";
        expr->print(indent + 1);
    }
};

// Assignment
class AssignNode : public ASTNode {
public:
    std::string varname;
    ASTPtr value;
    AssignNode(const std::string& name, ASTPtr val)
        : varname(name), value(val) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Assign(" << varname << ")\n";
        value->print(indent + 1);
    }
};

// Print
class PrintNode : public ASTNode {
public:
    ASTPtr expr;
    PrintNode(ASTPtr e) : expr(e) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Print\n";
        expr->print(indent + 1);
    }
};

// If
class IfNode : public ASTNode {
public:
    ASTPtr cond, then_branch;
    IfNode(ASTPtr c, ASTPtr t) : cond(c), then_branch(t) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "If\n";
        cond->print(indent + 1);
        then_branch->print(indent + 1);
    }
};

// If-else
class IfElseNode : public ASTNode {
public:
    ASTPtr cond, then_branch, else_branch;
    IfElseNode(ASTPtr c, ASTPtr t, ASTPtr e)
        : cond(c), then_branch(t), else_branch(e) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "If-Else\n";
        cond->print(indent + 1);
        then_branch->print(indent + 1);
        else_branch->print(indent + 1);
    }
};

// While
class WhileNode : public ASTNode {
public:
    ASTPtr cond, body;
    WhileNode(ASTPtr c, ASTPtr b) : cond(c), body(b) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "While\n";
        cond->print(indent + 1);
        body->print(indent + 1);
    }
};

// Statement list
class StmtListNode : public ASTNode {
public:
    ASTPtr first, second;
    StmtListNode(ASTPtr f, ASTPtr s) : first(f), second(s) {}
    void print(int indent = 0) const override {
        if (first) first->print(indent);
        if (second) second->print(indent);
    }
};

// Variable declaration
class DeclNode : public ASTNode {
public:
    std::string type;
    std::string name;
    DeclNode(const std::string& t, const std::string& n) : type(t), name(n) {}
    void print(int indent = 0) const override {
        print_indent(indent);
        std::cout << "Decl(" << type << " " << name << ")\n";
    }
};

// Factory functions for the parser
ASTPtr new_int(int value);
ASTPtr new_string(const std::string& val);
ASTPtr new_var(const std::string& name);
ASTPtr new_binop(const std::string& op, ASTPtr left, ASTPtr right);
ASTPtr new_unop(const std::string& op, ASTPtr expr);
ASTPtr new_assign(const std::string& name, ASTPtr expr);
ASTPtr new_print(ASTPtr expr);
ASTPtr new_if(ASTPtr cond, ASTPtr then_branch);
ASTPtr new_if_else(ASTPtr cond, ASTPtr then_branch, ASTPtr else_branch);
ASTPtr new_while(ASTPtr cond, ASTPtr body);
ASTPtr new_stmt_list(ASTPtr first, ASTPtr second);
ASTPtr new_decl(const std::string& type, const std::string& name);

extern ASTPtr ast_root; 

#endif