cmake_minimum_version(VERSION 3.16)

project(monkey02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SRC_FILES
    src/lexer.cpp
    src/parser.cpp
)

add_executable(parser_test
    test/parser_test.cpp
    ${SRC_FILES}
)

# TODO: We need to appropriately link stuff here, look at other CMakeLists.txt
target_link_libraries(parser_test lib/gtest/include/gtest.h)
