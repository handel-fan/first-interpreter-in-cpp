// parser.h
#include "../include/parser/parser.h"
#include "../include/ast.h"
#include "../include/lexer/lexer.h"
#include "../include/parser/parse_exception.h"
#include "../include/token/token.h"
#include <sstream>
#include <type_traits>

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
  case TokenType::LET: {
    auto stmt = ParseLetStatement();
    if (stmt) {
      return std::move(*stmt);
    } else {
      throw ParsingFailureException("Failed to parse let statement");
    }
  }
  case TokenType::RETURN: {
    auto ret_stmt = ParseReturnStatement();
    if (ret_stmt) {
      return std::move(*ret_stmt);
    } else {
      throw ParsingFailureException("Failed to parse return statement");
    }
  }
    // Will eventually add stuff like expressions to this switch statement
  default: {
    throw ParsingFailureException(
        "Failed parsing, couldn't find out what statement type was.");
  }
  }
}

// In C++, you can declare a reference or pointer to an abstract class
// (ast::Statement) You cannot instantiate, declare, or initialize an
// ast::Statement Furthermore, a pointer can point to different memory
// addresses in its lifetime. A reference can only point to 1 lvalue, and it
// must be initialized.
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
  // statement->value = this->ParseExpression();

  return nullptr;
}

std::optional<std::unique_ptr<ast::ReturnStatement>>
Parser::ParseReturnStatement() {}

bool Parser::ExpectPeek(TokenType t) {
  if (peekToken.type == t) {
    NextToken();
    return true;
  } else {

    // This is ai generated stuff I don't understand yet.
    // Revisit this less important code later.
    auto u = [](auto e) {
      using E = decltype(e);
      return static_cast<std::underlying_type_t<E>>(e);
    };
    std::ostringstream oss;
    oss << "Expected token type: " << u(t) << ", got " << u(peekToken.type)
        << " instead";

    errors.push_back(ParsingFailureException(oss.str()));
    return false;
  }
}

}; // namespace parser
