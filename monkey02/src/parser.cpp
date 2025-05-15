// parser.h
#include "../include/parser/parser.h"
#include "../include/ast.h"
#include "../include/lexer/lexer.h"
#include "../include/parser/parse_exception.h"
#include "../include/token/token.h"
#include <format>
#include <memory>

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

  while (currToken.type != TokenType::END_OF_FILE) {
    auto stmt = ParseStatement();
    NextToken();
  }

  return ast::Program();
}

std::unique_ptr<ast::Statement> Parser::ParseStatement() {

  switch (currToken.type) {
  case TokenType::LET:
    auto stmt = ParseLetStatement();
    if (stmt) {
      return std::move(*stmt);
    }
  case TokenType::RETURN:
    return ParseReturnStatement();
  default:
    return parseExpressionStatement();
  }
  if (ExpectPeek(TokenType::LET))
    // TODO: We have to "move" the letstatement as a statement. Idk what that
    // means yet
    if (auto letStatement = ParseLetStatement()) {
      return std::move(*letStatement);
    }

    else
      notimplementedpleaseignore();
  // else if (currToken.type == TokenType::RETURN) return
  // ParseReturnStatement(); else return parseExpressionStatement();
}

// In C++, you can declare a reference or pointer to an abstract class
// (ast::Statement) You cannot instantiate, declare, or initialize an
// ast::Statement Furthermore, a pointer can point to different memory addresses
// in its lifetime. A reference can only point to 1 lvalue, and it must be
// initialized.
std::optional<std::unique_ptr<ast::LetStatement>> Parser::ParseLetStatement() {
  std::unique_ptr<ast::LetStatement> statement =
      std::make_unique<ast::LetStatement>();

  if (!ExpectPeek(TokenType::IDENT)) {
    return std::nullopt;
  }

  this->NextToken();

  statement->name = ast::Identifier{currToken, currToken.literal};

  if (!ExpectPeek(TokenType::ASSIGN)) {
    return std::nullopt;
  }

  this->NextToken();
  statement->value = this->ParseExpression();

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
