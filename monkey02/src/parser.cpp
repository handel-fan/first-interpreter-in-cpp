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
  // NOTE: Does this expect Parser to be on a particular token? (First?)
  // Well I guess so, but we should put the responsibility of correct
  // calling on the caller, not on Parser.
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
    notimplementedpleaseignore();
  // else if (currToken.type == token::RETURN) return ParseReturnStatement();
  // else return parseExpressionStatement();
}

// In C++, you can declare a reference or pointer to an abstract class
// (ast::Statement) You cannot instantiate, declare, or initialize an
// ast::Statement Furthermore, a pointer can point to different memory addresses
// in its lifetime. A reference can only point to 1 lvalue, and it must be
// initialized.
ast::Statement *Parser::ParseLetStatement() {
  ast::Statement *statement = new ast::LetStatement{this->peekToken};

  if (!ExpectPeek(token::LET)) {
    return std::nullopt;
  }

  return statement;
}

bool Parser::ExpectPeek(TokenType t) {
  if (peekToken.type == t) {
    NextToken();
    return true;
  } else {
    errors.push_back(ParsingFailureException(std::format(
        "Expected token type: {}, got {} instead", t, peekToken.type)));
    return false;
  }
}

}; // namespace parser
