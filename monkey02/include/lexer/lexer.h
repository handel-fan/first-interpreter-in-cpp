// lexer.h
#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"
#include <string>

namespace lexer {
class Lexer {
public:
  Lexer(std::string str_input);
  void SkipWhitespace();
  void ReadChar();
  token::Token NextToken();
  std::string ReadIdentifier();
  std::string ReadDigit();
  unsigned char PeekChar();

private:
  std::string input;
  int position = 0;
  int read_position = 0;
  unsigned char cursor_char = '\0';
};
} // namespace lexer

#endif // LEXER_H
