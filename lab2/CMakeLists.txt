cmake_minimum_required(VERSION 3.16)

set (CMAKE_CXX_COMPILER "/usr/bin/g++")

project(TA_lab2)


set (CMAKE_CXX_STANDARD 20)
set (AUX_FLAGS "-O0 -coverage ")

set (CMAKE_CXX_FLAGS "-g -std=c++20 -Wall -Wextra -Wpedantic")

find_package(fmt REQUIRED)

#add_subdirectory(regex_gen)
add_executable(huinya.out main.cpp)
target_link_libraries(huinya.out fmt::fmt)
