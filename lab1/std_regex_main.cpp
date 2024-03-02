
#include "regex_constructor/regex_constructor.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main () {

    std::ifstream file("matching_strings.txt");
    std::regex re = rgx_ctor();
    std::string test_regex;

    if (file.is_open()) {
        while (!std::getline(file, test_regex, '\n').eof()) {
            std::cout << std::regex_match(test_regex, re) << ' ';
        }
        std::cout << std::endl;
        file.close();
    } else std::cerr << "File error." << std::endl;
}