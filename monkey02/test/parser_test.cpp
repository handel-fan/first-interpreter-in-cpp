#include "../include/lexer/lexer.h"
#include "../include/parser/parser.h"
#include "../lib/gtest/include/gtest.h"
#include <map>
#include <vector>
using ExpectedIdentifier = std::string;

namespace parser {

struct StatementTestCase {
  std::string ExpectedIdentifier;
  StatementTestCase(const std::string &str) : ExpectedIdentifier(str) {};
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
           << program.statements.size() << "statements";
  }

  // std::vector<std::map<ExpectedIdentifier, std::string>> test_cases = { {} }
  // parser::StatementTestCase xstatement{"x"}, ystatement{"y"},
  //   foobarstatement{"foobar"};

  std::vector<parser::StatementTestCase> test_cases = {
      StatementTestCase{"x"},
      StatementTestCase{"y"},
      StatementTestCase{"foobar"},
  };
}
for (int i = 0; i < test_cases.size(); i++) {
  if (!TestLetStatement(&program.statements[0], test_cases[0])) {
    FAIL() << "";
  }
}
}

bool TestLetStatement(ast::Statement *s, std::string name) {
  ast::LetStatement *letStatement = dynamic_cast<ast::LetStatement *>(s);
  if (!letStatement) {
    return false;
  }
  if (letStatement->TokenLiteral() != "let") {
    return false;
  }
  if (letStatement->name->value != name) {
    return false;
  }
  if (letStatement->name->TokenLiteral() != name) {
    return false;
  }

  return true;
}

} // namespace parser
