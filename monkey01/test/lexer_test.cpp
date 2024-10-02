#include "../include/lexer/lexer.h"
#include "../lib/gtest/include/gtest.h"
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
      {token::ASSIGN, "="}, {token::PLUS, "+"},     {token::LPAREN, "("},
      {token::RPAREN, ")"}, {token::LBRACE, "{"},   {token::RBRACE, "}"},
      {token::COMMA, ","},  {token::SEMICOLON, ";"}};

  lexer::Lexer lexerInstance{input};
  for (const auto &test_elem : tests) {
    auto token = lexerInstance.NextToken();
    EXPECT_EQ(token.type, test_elem.first) << "\nWrong Token Type. Expected " +
                                                  test_elem.first + "got " +
                                                  token.type;

    EXPECT_EQ(token.literal, test_elem.second)
        << "\nWrong Token Literal. Expected " + test_elem.second + "got " +
               token.literal;
  }
}

TEST(Monkey1, BasicMonkey) {
  std::string input = "let five = 5;"
                      "let ten = 10;"
                      "let add = fn(x, y) {"
                      "x + y;"
                      "};"
                      "let result = add(five, ten);"
      //
      ;
  std::vector<std::pair<ExpectedType, Literal>> tests = {
      //
      {token::LET, "let"},     {token::IDENT, "five"},
      {token::ASSIGN, "="},    {token::INT, "5"},
      {token::SEMICOLON, ";"},

      {token::LET, "let"},     {token::IDENT, "ten"},
      {token::ASSIGN, "="},    {token::INT, "10"},
      {token::SEMICOLON, ";"},

      {token::LET, "let"},     {token::IDENT, "add"},
      {token::ASSIGN, "="},    {token::FUNCTION, "fn"},
      {token::LPAREN, "("},    {token::IDENT, "x"},
      {token::COMMA, ","},     {token::IDENT, "y"},
      {token::RPAREN, ")"},    {token::LBRACE, "{"},
      {token::IDENT, "x"},     {token::PLUS, "+"},
      {token::IDENT, "y"},     {token::SEMICOLON, ";"},
      {token::RBRACE, "}"},    {token::SEMICOLON, ";"},

      {token::LET, "let"},     {token::IDENT, "result"},
      {token::ASSIGN, "="},    {token::IDENT, "add"},
      {token::LPAREN, "("},    {token::IDENT, "five"},
      {token::COMMA, ","},     {token::IDENT, "ten"},
      {token::SEMICOLON, ";"}, {token::RPAREN, ")"},
      {token::END_OF_FILE, ""}

  };

  lexer::Lexer lexerInstance{input};
  int i = 0;
  for (const auto &test_elem : tests) {
    auto token = lexerInstance.NextToken();
    EXPECT_EQ(token.type, test_elem.first)
        << "\nWrong Token Type. Expected " + test_elem.first + " got " +
               token.type + ". Token Literal was " + token.literal +
               ". The test number was: " + std::to_string(i) + ".";

    EXPECT_EQ(token.literal, test_elem.second)
        << "\nWrong Token Literal. Expected " + test_elem.second + " got " +
               token.literal;
    i++;
  }
}
} // namespace lexer
