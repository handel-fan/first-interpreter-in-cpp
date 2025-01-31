// parser.h

#ifndef PARSER_H
#define PARSER_H

#include "../ast.h"
#include "../lexer/lexer.h"
#include "../token/token.h"
#include <optional>

namespace parser {
class Parser {
public:
  Parser(lexer::Lexer lexer);

  void NextToken();
  ast::Program ParseProgram();
  ast::Statement *ParseStatement();
  ast::Statement *ParseLetStatement();
  bool ExpectPeek(TokenType expectedToken);
  std::vector<std::exception> errors;

private:
  lexer::Lexer lexer;

  token::Token currToken;
  token::Token peekToken;
};
} // namespace parser
#endif // PARSER_H
