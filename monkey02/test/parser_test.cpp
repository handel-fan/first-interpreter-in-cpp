#include "../include/lexer/lexer.h"
#include "../include/parser/parser.h"
#include "../lib/gtest/include/gtest.h"
#include <vector>
using ExpectedIdentifier = std::string;

namespace parser {

// Forward declaration of TestLetStatement
bool TestLetStatement(ast::Statement *s, std::string name);

struct LetStmtTest {
  std::string ExpectedIdentifier;
  LetStmtTest(const std::string &str) : ExpectedIdentifier(str) {};
  // TODO: Will add stuff for expressions later.
};

struct RetStmtTest {
  // TODO: Change from ident to expected expression later I guess.
  std::string ExpectedIdentifier;
  RetStmtTest(const std::string &str) : ExpectedIdentifier(str) {};
};

std::string letStmtInput = "let x = 5;\n"
                           "let y = 10;\n"
                           "let foobar = 838383;\n";
std::vector<parser::LetStmtTest> letStmtTestCases = {
    LetStmtTest{"x"},
    LetStmtTest{"y"},
    LetStmtTest{"foobar"},
};

// NOTE: We're skipping asserting the value for now.
bool TestLetStatement(ast::Statement *s, std::string name) {
  ast::LetStatement *letStatement = dynamic_cast<ast::LetStatement *>(s);
  if (!letStatement) {
    return false;
  }
  if (letStatement->TokenLiteral() != "let") {
    return false;
  }
  if (letStatement->name.value != name) {
    return false;
  }
  if (letStatement->name.TokenLiteral() != name) {
    return false;
  }

  return true;
}

TEST(Parser, LetStatement) {

  parser::Parser p = parser::Parser(lexer::Lexer(letStmtInput));
  ast::Program program = p.ParseProgram();
  if (program.statements.size() == 0) {
    FAIL() << "ParseProgram had no statements";
  }

  if (program.statements.size() != 3) {
    FAIL() << "Expected 3 statements, got" << program.statements.size()
           << " statements";
  }

  for (int i = 0; i < letStmtTestCases.size(); i++) {
    if (!TestLetStatement(&program.statements[i],
                          letStmtTestCases[i].ExpectedIdentifier)) {
      FAIL() << "TestLetStatement failed for test case " << i;
    }
  }
}

bool TestReturnStatement(ast::Statement *s) {
  ast::ReturnStatement *retStatement = dynamic_cast<ast::ReturnStatement *>(s);
  if (!retStatement) {
    return false;
  }
  if (retStatement->TokenLiteral() != "return") {
    return false;
  }
  // TODO: Add check for correct expression return.

  return true;
}
std::string retStmtInput = "return 5;"
                           "return 10;"
                           "return 838383;";

std::vector<parser::RetStmtTest> retStmtTestCases = {
    RetStmtTest{"x"},
    RetStmtTest{"y"},
    RetStmtTest{"foobar"},
};
TEST(Parser, ReturnStatement) {
  parser::Parser p{lexer::Lexer(retStmtInput)};
  ast::Program program = p.ParseProgram();
  if (program.statements.size() != 3) {
    FAIL() << "Expected 1 statements, got" << program.statements.size()
           << " statements";
  }
  for (int iter = 0; iter < 3; iter++) {
    if (!TestReturnStatement(&program.statements[iter])) {
      FAIL() << "TestReturnStatement failed for test case " << iter;
    }
  }
}

} // namespace parser
