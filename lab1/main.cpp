
#include <iostream>
#include "check_string.h"


int main() {

    /*std::cout << "In use: ";

    #ifdef STD_REGEX
    std::cout << "std::regex";
    #elif defined FLEX 
    std::cout << "flex++";
    #elif defined SMC 
    std::cout << "smc";
    #endif
    std::cout << std::endl;*/

    std::string line;

    while (!std::getline(std::cin, line).eof()) {
        //bool result = check_string(line);
        //std::cout << result << ' ';
        check_string(line);
    } 
    //std::cout << std::endl;

    return 0;
}

