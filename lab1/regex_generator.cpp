
#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "regex_gen/regex_gen.h"

//  statement := variable_name ([operation_sign] [statement])*
//  variable_name := {!, [a-z], [0-9]} any case, up to 16 symbols
//  1st symbol - letter/!, ! only 1st
//  operation_sign - {&, |, ^} - statement follows

int main (int argc, char **argv) {
    std::srand(time(NULL));
    if (!argv[1]) throw std::runtime_error("No arguments");
    make_regex_data(std::atoi(argv[1]));
    make_shit_data(std::atoi(argv[1]));
}