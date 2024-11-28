cmake_minimum_required(VERSION 3.10)
project(LexerREPL)
set(CMAKE_LINKER ld.lld)
set(CMAKE_CXX_STANDARD 23)

include_directories(../../include/)
add_library(lexer ../../src/lexer.cpp ../../src/token.cpp)
add_executable(lexer_repl lexer_repl.cpp)
target_link_libraries(lexer_repl lexer)
