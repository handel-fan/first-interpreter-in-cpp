#include "../include/lexer/lexer.h"
#include "../include/parser/parser.h"
#include "../lib/gtest/include/gtest.h"
#include <map>
#include <vector>
using ExpectedIdentifier = std::string;

namespace parser {

struct TestCase {
  std::string ExpectedIdentifier;
  TestCase(const std::string &str) : ExpectedIdentifier(str){};
};

//
TEST(Parser, BasicParser) {
  std::string input = "let x = 5;\n"
                      "let y = 10;\n"
                      "let foobar = 838383;\n";

  lexer::Lexer l = lexer::Lexer(input);
  parser::Parser p = parser::Parser(l);
  ast::Program program = p.ParseProgram();
  if (program.statements.size() == 0) {
    FAIL() << "ParseProgram had no statements";
  }
  if (program.statements.size() != 3) {
    FAIL() << "ParseProgram did not have 3 statements, got"
           << program.statements.size();
  }
  // std::vector<std::map<ExpectedIdentifier, std::string>> test_cases = { {} }
  parser::TestCase xstatement, ystatement, foobarstatement = TestCase{"x"},
                                           TestCase("x"), TestCase("x");
  std::vector<parser::TestCase> test_cases = {
      TestCase("x"),
      TestCase("y"),
      TestCase("foobar"),
  };
}

} // namespace parser
