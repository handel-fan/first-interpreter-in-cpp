#include "../token/token.h"
#include <string>

namespace lexer {
//
struct Lexer {
  std::string input;
  int position = 0;
  int read_position = 0;
  unsigned char cursor_char = '\0';
  Lexer(std::string str_input) : input(str_input) {
    //
    //
    this->readChar();
  }

  void readChar() {
    if (read_position >= input.length()) {
      cursor_char = 0;
    } else {
      cursor_char = input.at(read_position);
    }
    position = read_position;
    read_position++;
    //
  }

  token::Token NextToken() {
    token::Token tok;
    auto curr_char = this->cursor_char;
    switch (curr_char) {
    case '=':
      tok = token::Token{token::ASSIGN, std::string(1, curr_char)};
    case ';':
      tok = token::Token{token::SEMICOLON, std::string(1, curr_char)};
    case '(':
      tok = token::Token{token::LPAREN, std::string(1, curr_char)};
    case ')':
      tok = token::Token{token::RPAREN, std::string(1, curr_char)};
    case ',':
      tok = token::Token{token::COMMA, std::string(1, curr_char)};
    case '+':
      tok = token::Token{token::PLUS, std::string(1, curr_char)};
    case '{':
      tok = token::Token{token::LBRACE, std::string(1, curr_char)};
    case '}':
      tok = token::Token{token::RBRACE, std::string(1, curr_char)};
    case 0:
      tok = token::Token{token::END_OF_FILE, ""};
    }
    this->readChar();
    return tok;
  }
};

} // namespace lexer
  //
int main() {
  //
  //
  lexer::Lexer l{"j"};
}
