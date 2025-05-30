#ifndef TOKEN_H
#define TOKEN_H

// token.h

#include "constants.h"
#include "types.h"
#include <string>

namespace token {
struct Token {
  TokenType type;
  std::string literal;
};

TokenType LookupIdent(std::string ident);

} // namespace token
#endif // TOKEN_H
