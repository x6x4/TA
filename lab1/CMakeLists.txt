cmake_minimum_required(VERSION 3.16)

set (CMAKE_CXX_COMPILER "/usr/bin/g++")

project(TA_lab1)

set (CMAKE_CXX_STANDARD 20)
set (AUX_FLAGS "-O0 -coverage ")

set (FLAG "FLEX")
set (CMAKE_CXX_FLAGS "-O2 -std=c++20 -Wall -Wextra -Wpedantic -D${FLAG}")


add_subdirectory(std_regex)

if (FLAG STREQUAL "STD_REGEX")
    add_executable(my_regex.out main.cpp)
    target_link_libraries(my_regex.out std_regex)

elseif(FLAG STREQUAL "FLEX")
    add_subdirectory(flex)
    add_executable(my_regex.out main.cpp)
    target_link_libraries(my_regex.out flex_regex)

elseif(FLAG STREQUAL "SMC")
    add_subdirectory(smc)

endif()


#  random strings generator

add_subdirectory(regex_gen)
add_executable(std_regex_gen.out regex_generator.cpp)
target_link_libraries(std_regex_gen.out regex_gen std_regex)
