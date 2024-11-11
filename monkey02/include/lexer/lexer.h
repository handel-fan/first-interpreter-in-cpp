// lexer.h
#ifndef LEXER_H
#define LEXER_H

// lexer.h
#include "../token/token.h"
#include <string>

namespace lexer {
struct Lexer {
  std::string input;
  int position = 0;
  int read_position = 0;
  unsigned char cursor_char = '\0';
  Lexer(std::string str_input);
  void SkipWhitespace();
  void ReadChar();
  token::Token NextToken();
  std::string ReadIdentifier();
  std::string ReadDigit();
  unsigned char PeekChar();
  token::Token PeekToken();
};
} // namespace lexer

#endif // LEXER_H
