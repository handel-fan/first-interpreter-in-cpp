cmake_minimum_required(VERSION 3.10)
project(MyInterpreter)
set(CMAKE_LINKER ld.lld)

set(CMAKE_CXX_STANDARD 23)

# Include directories
include_directories(include)

# Lexer sources
set(LEXER_SOURCES src/lexer.cpp)
set(TOKEN_SOURCES src/token.cpp)

# Add the lexer library
add_library(lexer ${LEXER_SOURCES} ${TOKEN_SOURCES})

# Add the executable for tests
add_executable(lexer_test test/lexer_test.cpp)

link_directories(${CMAKE_SOURCE_DIR}/lib/gtest)

# Link the lexer library with the test executable
target_link_libraries(lexer_test lexer ${CMAKE_SOURCE_DIR}/lib/gtest/libgtest.a
                      ${CMAKE_SOURCE_DIR}/lib/gtest/libgtest_main.a)
