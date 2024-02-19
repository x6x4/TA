#include "regex_constructor.h"

std::regex regex_constructor () {

    std::string var_name_first_sym("(!|[[:alpha:]])");
    std::string var_name_remainder("[[:alnum:]]{0,15}");
    std::string var_name = "(" + var_name_first_sym + var_name_remainder + ")";
    std::string spaces = "([ \t\r\f\v])*";

    std::string oper_sgn("[&, |, ^]");
    std::string regex_str = "^" + spaces + var_name + 
        "(" + spaces + oper_sgn + spaces + var_name + spaces + ")*" + "$";
    return std::regex(regex_str);
}