#include "../include/lexer/lexer.h"
#include <string>

namespace lexer {

bool IsLetter(unsigned char byte) {
  return byte == 95                      // underscore
         || (byte >= 65 && byte <= 90)   // lowercase
         || (byte >= 97 && byte <= 122); // uppercase
}

bool IsDigit(unsigned char byte) {
  // 48 is 1 in ascii, 57 is 9
  return byte >= 48 && byte <= 57;
}

Lexer::Lexer(std::string str_input) : input(str_input) { this->ReadChar(); }

void Lexer::SkipWhitespace() {
  while (cursor_char == 9     // horizontal tab
         || cursor_char == 32 // space
         || cursor_char == 10 // newline
         || cursor_char == 13 // carriage return
  ) {
    this->ReadChar();
  }
}

void Lexer::ReadChar() {
  if (read_position >= input.length()) {
    cursor_char = 0;
  } else {
    cursor_char = input.at(read_position);
  }
  position = read_position;
  read_position++;
}

unsigned char Lexer::PeekChar() {
  if (read_position >= input.length()) {
    return 0;
  } else
    return input.at(read_position);
}

std::string Lexer::ReadIdentifier() {
  int ident_start_index = position;
  while (IsLetter(cursor_char)) {
    this->ReadChar();
  }
  return input.substr(ident_start_index, position - ident_start_index);
}

std::string Lexer::ReadDigit() {
  int digit_start_index = position;
  while (IsDigit(cursor_char)) {
    this->ReadChar();
  }
  return input.substr(digit_start_index, position - digit_start_index);
}

token::Token Lexer::NextToken() {
  this->SkipWhitespace();
  token::Token tok;
  auto curr_char = this->cursor_char;
  unsigned char next_char = PeekChar();
  switch (curr_char) {
  case '=':
    if (next_char == '=') {
      char first_char = cursor_char;
      ReadChar();
      tok = token::Token{TokenType::EQ,
                         std::string{first_char} +
                             std::string{static_cast<char>(cursor_char)}};
      break;
    }
    tok = token::Token{TokenType::ASSIGN, std::string(1, curr_char)};
    break;
  case ';':
    tok = token::Token{TokenType::SEMICOLON, std::string(1, curr_char)};
    break;
  case '(':
    tok = token::Token{TokenType::LPAREN, std::string(1, curr_char)};
    break;
  case ')':
    tok = token::Token{TokenType::RPAREN, std::string(1, curr_char)};
    break;
  case ',':
    tok = token::Token{TokenType::COMMA, std::string(1, curr_char)};
    break;
  case '+':
    tok = token::Token{TokenType::PLUS, std::string(1, curr_char)};
    break;
  case '{':
    tok = token::Token{TokenType::LBRACE, std::string(1, curr_char)};
    break;
  case '}':
    tok = token::Token{TokenType::RBRACE, std::string(1, curr_char)};
    break;
  case '!':
    if (next_char == '=') {
      char first_char = cursor_char;
      ReadChar();
      tok = token::Token{TokenType::NOT_EQ,
                         std::string{first_char} +
                             std::string{static_cast<char>(cursor_char)}};
      break;
    }
    tok = token::Token{TokenType::BANG, std::string(1, curr_char)};
    break;
  case '-':
    tok = token::Token{TokenType::MINUS, std::string(1, curr_char)};
    break;
  case '/':
    tok = token::Token{TokenType::SLASH, std::string(1, curr_char)};
    break;
  case '*':
    tok = token::Token{TokenType::ASTERISK, std::string(1, curr_char)};
    break;
  case '<':
    tok = token::Token{TokenType::LT, std::string(1, curr_char)};
    break;
  case '>':
    tok = token::Token{TokenType::GT, std::string(1, curr_char)};
    break;
  case 0:
    tok = token::Token{TokenType::END_OF_FILE, ""};
    break;
  default:
    if (IsLetter(curr_char)) {
      std::string ident_literal = ReadIdentifier();
      return token::Token{token::LookupIdent(ident_literal), ident_literal};
    } else if (IsDigit(curr_char)) {
      auto digit_literal = ReadDigit();
      return token::Token{TokenType::INT, digit_literal};
    } else {
      tok = token::Token{TokenType::ILLEGAL, "ILLEGAL CHARACTER"};
    }
  }
  this->ReadChar();
  return tok;
}

} // namespace lexer
