#pragma once
 
#include <regex>
#include <string>

inline std::regex rgx_ctor () {

    std::string var_name_first_ch("(!|[[:alpha:]])");
    std::string var_name_rest("[[:alnum:]]{0,15}");
    std::string var_name = "(" + var_name_first_ch + var_name_rest + ")";
    std::string spaces = "([ \t\f\v])*";

    std::string oper_sgn("[&, |, ^]");
    std::string rgx_str = "^" + spaces + var_name + 
        "(" + spaces + oper_sgn + spaces + var_name + spaces + ")*" + "$";
    return std::regex(rgx_str);
}