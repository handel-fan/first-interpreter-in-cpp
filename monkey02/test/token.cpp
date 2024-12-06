#include "../include/token/constants.h"
#include <map>
#include <string>

namespace token {

struct Token {
  TokenType type;
  std::string literal;
};

TokenType LookupIdent(std::string ident) {
  if (keywords.find(ident) != keywords.end()) {
    return keywords.at(ident);
  }
  return IDENT;
}

} // namespace token
