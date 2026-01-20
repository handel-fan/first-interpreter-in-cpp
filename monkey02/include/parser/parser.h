// parser.h

#ifndef PARSER_H
#define PARSER_H

#include "../ast.h"
#include "../lexer/lexer.h"
#include "../token/token.h"
#include <memory>
#include <optional>

namespace parser {
class Parser {
public:
  Parser(lexer::Lexer lexer);

  void NextToken();
  std::unique_ptr<ast::Program> ParseProgram();
  std::optional<ast::Statement *> ParseStatement();
  std::optional<ast::LetStatement *> ParseLetStatement();
  std::optional<ast::ReturnStatement *> ParseReturnStatement();

  bool ExpectPeek(TokenType expectedToken);
  std::vector<std::exception> errors;

private:
  lexer::Lexer lexer;

  token::Token currToken;
  token::Token peekToken;
};
} // namespace parser
#endif // PARSER_H
