
#include <regex>
#include <iostream>
#include <string>

//  statement := variable name ([operation sign] [statement])*
//  variable name := {!, [a-z], [0-9]} any case, up to 16 symbols
//  1st symbol - letter/!, ! only 1st
//  operation sign - {&, |, ^} - statement follows

int main () {

    std::string s1 = "myVariable21";
    std::string s2 = "Class|h2&gr89";
    std::string s3 = "!a^y1";
    std::string s4 = "b&l";
    std::string err1 = "2_var";
    std::string err2 = "var&";
    std::string err3 = "vakldjsndwedjjwnendn";
    
    std::string var_name_first_sym("((!|[[:alpha:]])");
    std::string var_name_remainder("[[:alnum:]]{0,15})");
    std::string var_name = var_name_first_sym + var_name_remainder;

    std::string operation_sgn("[&, |, ^]");
    std::string regex_str = 
        "^" + var_name + "(" + operation_sgn + var_name + ")*" + "$";
    std::string regex_str2 = 
        "^(" + var_name + operation_sgn + ")*" + var_name + "$";
    std::cout << regex_str2 << std::endl;
    std::regex re(regex_str2);

    std::cout << std::regex_match(s1, re) << std::endl;
    std::cout << std::regex_match(s2, re) << std::endl;
    std::cout << std::regex_match(s3, re) << std::endl;
    std::cout << std::regex_match(s4, re) << std::endl;
    std::cout << std::regex_match(err1, re) << std::endl;
    std::cout << std::regex_match(err2, re) << std::endl;
    std::cout << std::regex_match(err3, re) << std::endl;
}