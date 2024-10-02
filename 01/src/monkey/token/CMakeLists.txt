cmake_minimum_required(VERSION 3.10)

project(token)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

set(SOURCE_FILES token.cpp)

add_library(token ${SOURCE_FILES})
