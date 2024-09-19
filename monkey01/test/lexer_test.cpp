#include "../include/lexer/lexer.h"
#include "../lib/gtest.h"
#include <vector>
using ExpectedType = TokenType;
using Literal = std::string;

namespace lexer {

std::string input2 = "let five = 5;"
                     "let ten = 10;"
                     "let add = fn(x, y) {"
                     "x + y;"
                     "};"
                     "let result = add(five, ten);"
                     "let result = add(five, ten);"
    //
    ;
TEST(NextToken, BasicNextToken) {
  std::string input = "=+(){},;";

  std::vector<std::pair<ExpectedType, Literal>> tests = {
      //
      {token::ASSIGN, "="},     {token::PLUS, "+"},  {token::LPAREN, "["},
      {token::RPAREN, "]"},     {token::COMMA, ","}, {token::SEMICOLON, ";"},
      {token::END_OF_FILE, ";"}};

  lexer::Lexer lexerInstance{input};
  for (const auto &test_elem : tests) {
    auto token = lexerInstance.NextToken();
    EXPECT_EQ(token.type, test_elem.first)
        << "\nWrong Token Expected Type. Expected " + test_elem.first + "got " +
               token.type;

    EXPECT_EQ(token.literal, test_elem.second)
        << "\nWrong Token Literal. Expected " + test_elem.second + "got " +
               token.literal;
  }

  //
} // namespace lexer

// sl.dkjfsldkfj
} // namespace lexer
  // Teddy is a fucking cunt.
