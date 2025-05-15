// #include "../include/token/constants.h"
#include "../include/token/token.h"
#include <string>

namespace token {

TokenType LookupIdent(std::string ident) {
  if (keywords.find(ident) != keywords.end()) {
    return keywords.at(ident);
  }
  return TokenType::IDENT;
}

} // namespace token
