#include <regex>
#include <string>
#include "std_regex.h"


std::string var_name_ctor() {
    std::string var_name_first_ch("((?:!|[[:alpha:]])");
    std::string var_name_rest("\\w{0,15})");
    std::string var_name = var_name_first_ch + var_name_rest;

    return var_name;
}

//  regex itself
std::regex rgx_ctor () {

    std::string var_name = var_name_ctor();
    std::string spaces = "\\s*";

    std::string oper_sgn("[&|^]");
    std::string rgx_base = spaces + var_name + 
        "(" + spaces + oper_sgn + spaces + var_name + spaces + ")*";
    std::string rgx_str = "^" + rgx_base + "$";

    return std::regex(rgx_str, std::regex_constants::optimize);
}


bool StdCheckString::operator()(const std::string& str) {
    std::regex re = rgx_ctor();
    std::regex vn = std::regex(var_name_ctor(), std::regex_constants::optimize);

    std::sregex_iterator iter(str.begin(), str.end(), re);
    std::sregex_iterator end;
    
    bool res = std::regex_match(str, re);
    if (!res) return false; 

    std::smatch match;
    std::string::const_iterator searchStart = str.begin();

    while (std::regex_search(searchStart, str.end(), match, vn)) {

        // Print all captures (groups)
        for (size_t i = 1; i < match.size(); ++i) { // Start from 1 to skip the full match 
        if (match[i].matched) {
            addVar(match[i].str()); 
        }
        }

        searchStart = match.suffix().first; // Move searchStart to the next position
    }

    return true;
}


//  make class without global state
