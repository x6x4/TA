cmake_minimum_required(VERSION 3.16)

set (CMAKE_CXX_COMPILER "/usr/bin/g++")

project(TA_lab1)

set (CMAKE_CXX_STANDARD 20)
set (AUX_FLAGS "-O0 -coverage ")
set (CMAKE_MESSAGE_LOG_LEVEL "DEBUG")

set (CMAKE_CXX_FLAGS "-std=c++20 -Wall -Wextra -Wpedantic")
set (FLAG "SMC")

if (FLAG STREQUAL "STD_REGEX")
    add_subdirectory(std_regex)
    add_executable(my_regex.out main.cpp)
    target_link_libraries(my_regex.out std_regex)

elseif(FLAG STREQUAL "FLEX")
    find_package(FLEX REQUIRED)

    flex_target(lexer rgx_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
    add_executable(my_regex.out ${FLEX_lexer_OUTPUTS} flex_main.cpp)

elseif(FLAG STREQUAL "SMC")
    add_subdirectory(smc)

endif()


#  random strings generator

add_subdirectory(regex_gen)
add_executable(std_regex_gen.out regex_generator.cpp)
target_link_libraries(std_regex_gen.out regex_gen)
