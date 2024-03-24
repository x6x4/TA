
#include "huinya.h"
#include <iostream>
#include <string>

int main () {
    
    KYK_PARSER my_parser;
    std::string buf_str;
    std::getline(std::cin, buf_str);
    
    my_parser.compile(buf_str);
    //std::cout << my_parser;

    my_parser.make_graph();

    /*
    0 a 1
    1 b 2
    2 c 3
    0 d 4
    4 e 5
    5 f 3
    */
}