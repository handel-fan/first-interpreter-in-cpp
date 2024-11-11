// parser.h

#ifndef PARSER_H
#define PARSER_H

#include "../ast.h"
#include "../lexer/lexer.h"
#include "../token/token.h"

namespace parser {
struct Parser {
public:
  Parser(lexer::Lexer lexer) : l(lexer) {
    NextToken();
    NextToken();
  }
  lexer::Lexer l;

  token::Token currToken;
  token::Token peekToken;

  void NextToken() {
    currToken = peekToken;
    peekToken = l.NextToken();
  }

  ast::Program ParseProgram() {
    return ast::Program();
    //
  }
};
} // namespace parser

#endif // PARSER_H
