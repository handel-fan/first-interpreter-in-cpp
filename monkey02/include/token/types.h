#ifndef TYPES_H
#define TYPES_H
#include <string>

// types.h
// using TokenType = std::string;

enum class TokenType {

  ILLEGAL,
  END_OF_FILE,

  // Identifiers + literals
  IDENT,
  INT,

  // Operators
  ASSIGN,
  PLUS,
  MINUS,
  BANG,
  ASTERISK,
  SLASH,
  LT,
  GT,
  EQ,
  NOT_EQ,

  // Delimiters
  COMMA,
  SEMICOLON,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,

  // Keywords
  FUNCTION,
  LET,
  TRUE,
  FALSE,
  IF,
  ELSE,
  RETURN,
}; // namespace token

;
#endif // TYPES_H
