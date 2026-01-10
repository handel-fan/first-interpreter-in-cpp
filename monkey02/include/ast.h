// ast.h

#ifndef AST_H
#define AST_H

#include "../include/token/token.h"
#include <string>
#include <vector>

namespace ast {
struct Node {
  virtual std::string TokenLiteral() const = 0;
};

struct Statement : Node {
  std::vector<token::Token> lvalue_list;

  // FIXME: This should not return let
  std::string TokenLiteral() const override { return "let"; }
};

struct Expression : Node {};

struct Program : ast::Node {
  std::vector<ast::Statement> statements;
  std::string TokenLiteral() const override {
    if (statements.size() > 0) {
      return this->statements[0].TokenLiteral();
    } else {
      return "";
    }
  }
};

struct Identifier : Expression {
  token::Token token;
  std::string value;

  Identifier() : token(), value() {};
  Identifier(token::Token t, std::string v) : token(t), value(v) {};

  std::string TokenLiteral() const override { return token.literal; }
};

struct LetStatement : Statement {
  LetStatement() {};
  LetStatement(token::Token t) : token(t) {};
  token::Token token;
  Identifier name;
  Expression *value;

  std::string TokenLiteral() const override { return token.literal; }
};

struct ReturnStatement : Statement {
  ReturnStatement() {};
  ReturnStatement(token::Token t) : token(t) {};
  token::Token token;
  Expression *returnValue;

  std::string TokenLiteral() const override { return token.literal; }
};
} // namespace ast

#endif // AST_H
