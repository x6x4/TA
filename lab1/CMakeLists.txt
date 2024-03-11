cmake_minimum_required(VERSION 3.16)

set (CMAKE_CXX_COMPILER "/usr/bin/g++")

project(TA_lab1)

set (CMAKE_CXX_STANDARD 20)
set (AUX_FLAGS "-O0 -coverage ")

set (CMAKE_CXX_FLAGS "-std=c++20 -Wall -Wextra -Wpedantic")

#  flex

find_package(FLEX REQUIRED)

flex_target(lexer rgx_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
add_executable(flex.out ${FLEX_lexer_OUTPUTS} flex_main.cpp)

#  c++

add_subdirectory(regex_gen)
add_executable(std_regex.out std_regex_main.cpp)

add_executable(std_regex_gen.out regex_generator.cpp)
target_link_libraries(std_regex_gen.out regex_gen)
