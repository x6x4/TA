
#include <iostream>
#include "check_string.h"


int main() {

    std::string line;

    while (!std::getline(std::cin, line).eof()) {
        bool result = check_string(line);
        std::cout << result << ' ';
    } 
    std::cout << std::endl;

    return 0;
}

