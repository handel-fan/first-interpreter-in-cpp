// token.h

#include "constants.h"
#include "types.h"
#include <string>

namespace token {
struct Token {
  TokenType type;
  std::string literal;
};

} // namespace token
