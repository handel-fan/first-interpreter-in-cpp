#ifndef TOKEN_H
#define TOKEN_H

// token.h

// #include "constants.h"

#include "types.h"
#include <string>
#include <unordered_map>

namespace token {
struct Token {
  TokenType type;
  std::string literal;
};

const std::unordered_map<std::string, TokenType> keywords = {
    {"fn", TokenType::FUNCTION},   {"let", TokenType::LET},
    {"true", TokenType::TRUE},     {"false", TokenType::FALSE},
    {"if", TokenType::IF},         {"else", TokenType::ELSE},
    {"return", TokenType::RETURN},
};

TokenType LookupIdent(std::string ident);

} // namespace token
#endif // TOKEN_H
