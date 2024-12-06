// parser.h

#ifndef PARSER_H
#define PARSER_H

#include "../ast.h"
#include "../lexer/lexer.h"
#include "../token/token.h"

namespace parser {
struct Parser {
public:
  Parser(lexer::Lexer lexer);
  lexer::Lexer l;

  token::Token currToken;
  token::Token peekToken;

  void NextToken();

  ast::Program ParseProgram();
};
} // namespace parser
#endif // PARSER_H
