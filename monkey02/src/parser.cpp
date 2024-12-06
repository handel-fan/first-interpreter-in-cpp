// parser.h

#include "../include/parser/parser.h"
#include "../include/ast.h"
#include "../include/lexer/lexer.h"

namespace parser {
Parser::Parser(lexer::Lexer lexer) : l(lexer) {
  NextToken();
  NextToken();
}

void Parser::NextToken() {
  currToken = peekToken;
  peekToken = l.NextToken();
}

ast::Program Parser::ParseProgram() { return ast::Program(); }
}; // namespace parser
