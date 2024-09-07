#include "../token/constants.h"
#include "include/gtest.h"
#include <vector>
using ExpectedType = TokenType;
using Literal = std::string;

namespace lexer {

TEST(NextToken, BasicNextToken) {
  std::string input = "=+(){},;";
  std::string input2 = "let five = 5;"
                       "let ten = 10;"
                       "let add = fn(x, y) {"
                       "x + y;"
                       "};"
                       "let result = add(five, ten);"
                       "let result = add(five, ten);"
      //
      ;

  std::vector<std::pair<ExpectedType, Literal>> tests = {
      //
      {token::ASSIGN, "="},     {token::PLUS, "+"},  {token::LPAREN, "["},
      {token::RPAREN, "]"},     {token::COMMA, ","}, {token::SEMICOLON, ";"},
      {token::END_OF_FILE, ";"}};

  lexer::Lexer lexerInstance{input};
  for (const auto &test_elem : tests) {
    std::pair<ExpectedType, Literal> token = lexerInstance.NextToken();
    EXPECT_EQ(token.first, test_elem.first)
        << "\nWrong Token Expected Type. Expected " + test_elem.first + "got " +
               token.first;

    EXPECT_EQ(token.second, test_elem.second)
        << "\nWrong Token Literal. Expected " + test_elem.second + "got " +
               token.second;
  }

  EXPECT_EQ(true, true);
  //
} // namespace lexer

// sl.dkjfsldkfj
} // namespace lexer
