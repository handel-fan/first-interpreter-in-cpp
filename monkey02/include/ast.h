// ast.h

#ifndef AST_H
#define AST_H

#include "../include/token/token.h"
#include "token/constants.h"
#include <string>
#include <vector>

namespace ast {
struct Node {
  virtual std::string TokenLiteral() = 0;
};

struct Statement : Node {};

struct Expression : Node {};

struct Program : ast::Node {
  std::vector<ast::Statement> statements;
  std::string TokenLiteral() {
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

  std::string TokenLiteral() override { return token.literal; }
};

struct LetStatement : Statement {
  token::Token token;
  Identifier *name;
  Expression *value;

  std::string TokenLiteral() override { return token.literal; }
};

} // namespace ast

#endif // AST_H
