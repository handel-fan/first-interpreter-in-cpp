cmake_minimum_required(VERSION 3.10)
project(FooLexer)
set(CMAKE_LINKER ld.lld)

set(CMAKE_CXX_STANDARD 23)

include_directories(../include/)
add_library(lexer ../src/lexer.cpp ../src/token.cpp)
add_executable(foolexer foo_lexer_main.cpp)

target_link_libraries(foolexer lexer)
