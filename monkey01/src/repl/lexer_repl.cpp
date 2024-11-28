#include "../../include/lexer/lexer.h"
#include "../../include/token/token.h"
#include <iostream>

int main() {
  std::cout << "Starting REPL. ctrl-c to exit." << std::endl;
  std::cout << ">> ";
  std::string input{};
  while (std::cin >> input) {
    lexer::Lexer lex = lexer::Lexer{input};
    token::Token tok = lex.NextToken();
    while (tok.type != token::END_OF_FILE) {
      std::cout << "The following token: " + tok.literal +
                       " of the type: " + tok.type + " was lexed."
                << std::endl;
      tok = lex.NextToken();
      std::cout << ">> ";
    }
  }
}
