// lexer.h
#include "../../token/include/token.h"
#include <string>

namespace lexer {
struct Lexer {
  std::string input;
  int position = 0;
  int read_position = 0;
  unsigned char cursor_char = '\0';
  Lexer(std::string str_input);
  void readChar();
  token::Token NextToken();
};
} // namespace lexer
