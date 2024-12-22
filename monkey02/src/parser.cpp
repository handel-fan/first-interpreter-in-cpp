// parser.h

#include "../include/parser/parser.h"
#include "../include/ast.h"
#include "../include/lexer/lexer.h"
#include "../include/parser/parse_exception.h"
#include "../include/token/constants.h"
#include "../include/token/token.h"
#include <format>

namespace parser {
Parser::Parser(lexer::Lexer lexer) : lexer(lexer) {
  NextToken();
  NextToken();
}

void Parser::NextToken() {
  currToken = peekToken;
  peekToken = lexer.NextToken();
}

ast::Program Parser::ParseProgram() {
  int x = 54;
  ast::Program program{};
  program.statements = std::vector<ast::Statement>();

  while (currToken.type != token::END_OF_FILE) {
    auto stmt = ParseStatement();
    NextToken();
  }

  return ast::Program();
}

ast::Statement *Parser::ParseStatement() {
  if (currToken.type == token::LET)
    return ParseLetStatement();
  else
    return nullptr;
  // else if (currToken.type == token::RETURN) return ParseReturnStatement();
  // else return parseExpressionStatement();
}

ast::Statement *Parser::ParseLetStatement() {
  //
  return ast::LetStatement();
}

bool Parser::ExpectPeek(token::Token t) {
  //
  if (peekToken.type == t.type) {
    NextToken();
    return true;
  } else {
    throw new ParseException(std::format("Expected token type: {}", t.type));
  }
}

}; // namespace parser
