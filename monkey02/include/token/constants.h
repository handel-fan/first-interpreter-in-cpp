#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "types.h"
#include <map>
#include <string>

namespace token {
const TokenType ILLEGAL = "ILLEGAL";
const TokenType END_OF_FILE = "";

// Identifiers + literals
const TokenType IDENT = "IDENT"; // add, foobar, x, y, ...
const TokenType INT = "INT";     // 1343456

// Operators
const TokenType ASSIGN = "=";
const TokenType PLUS = "+";
const TokenType MINUS = "-";
const TokenType BANG = "!";
const TokenType ASTERISK = "*";
const TokenType SLASH = "/";
const TokenType LT = "<";
const TokenType GT = ">";
const TokenType EQ = "==";
const TokenType NOT_EQ = "!=";

// Delimiters
const TokenType COMMA = ",";
const TokenType SEMICOLON = ";";
const TokenType LPAREN = "(";
const TokenType RPAREN = ")";
const TokenType LBRACE = "{";
const TokenType RBRACE = "}";

// Keywords
const TokenType FUNCTION = "FUNCTION";
const TokenType LET = "LET";
const TokenType TRUE = "TRUE";
const TokenType FALSE = "FALSE";
const TokenType IF = "IF";
const TokenType ELSE = "ELSE";
const TokenType RETURN = "RETURN";
const std::map<std::string, TokenType> keywords = {
    {"fn", FUNCTION}, {"let", LET},   {"true", TRUE},     {"false", FALSE},
    {"if", IF},       {"else", ELSE}, {"return", RETURN},
};
} // namespace token
#endif // CONSTANTS_H
