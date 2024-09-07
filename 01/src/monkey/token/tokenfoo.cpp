#include "../token/token.cpp"
#include <iostream>
#include <stdio.h>

int main() {

  token::Token mytoken{token::INT, "5"};

  auto fooIdent = token::LookupIdent("fn");
  std::cout << fooIdent << std::endl;
  // sldfkjs sldfkjs sldfkjs sldfkjs
}
