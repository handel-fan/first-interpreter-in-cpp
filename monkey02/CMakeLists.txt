cmake_minimum_required(VERSION 3.16)

project(monkey02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SRC_FILES
    src/lexer.cpp
    src/parser.cpp
    src/token.cpp
)

add_executable(parser_test
    test/parser_test.cpp
    ${SRC_FILES}
)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
)

FetchContent_MakeAvailable(googletest)

target_link_libraries(parser_test gtest gtest_main)

