cmake_minimum_required(VERSION 3.16)

set (CMAKE_CXX_COMPILER "/usr/bin/g++")

project(TA_lab3)

set (CMAKE_CXX_STANDARD 20)
set (AUX_FLAGS "-O0 -coverage ")

set (CMAKE_CXX_FLAGS "-std=c++20 -Wall -Wextra -Wpedantic")

#  flex

find_package(FLEX REQUIRED)

flex_target(lexer lexer-huexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
add_executable(flex.out ${FLEX_lexer_OUTPUTS} flex_main.cpp)