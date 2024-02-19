
#include <iostream>
#include "regex_constructor.cpp"


//  statement := variable name ([operation sign] [statement])*
//  variable name := {!, [a-z], [0-9]} any case, up to 16 symbols
//  1st symbol - letter/!, ! only 1st
//  operation sign - {&, |, ^} - statement follows

int main () {

    std::string s1 = " myVariable21";
    std::string s2 = "Class |     h2&gr89";
    std::string s3 = "!a^y1     ";
    std::string s4 = "b&l";
    std::string err1 = "2_var";
    std::string err2 = "var&";
    std::string err3 = "vakldjsndwedjjwnendn";
    std::string err4 = "ddd\nff";

    std::regex re = regex_constructor();

    std::cout << std::regex_match(s1, re) << std::endl;
    std::cout << std::regex_match(s2, re) << std::endl;
    std::cout << std::regex_match(s3, re) << std::endl;
    std::cout << std::regex_match(s4, re) << std::endl;
    std::cout << std::regex_match(err1, re) << std::endl;
    std::cout << std::regex_match(err2, re) << std::endl;
    std::cout << std::regex_match(err3, re) << std::endl;
    std::cout << std::regex_match(err4, re) << std::endl;
}