
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>


size_t spaces_limit = 2;
size_t rest_repeat_limit = 8;


const std::string alnum_charset =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

const std::string alpha_charset =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

const std::string oper_sgn_charset = 
        "&|^";

const std::string spaces_charset = 
        " \t\v\f";


std::string random_string( size_t length, const std::string &charset ) {

    auto randchar = [ &charset ]() -> char
    {
        const size_t max_index = (charset.size() - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );

    return str;
}

std::string gen_var_name () {
    std::string var_name_first_ch;

    bool alpha_first_char = rand() % 2;
    if (!alpha_first_char) var_name_first_ch = "!";
    else                   var_name_first_ch = random_string(1, alpha_charset);

    size_t rest_len = rand() % 15;
    std::string var_name_rest = random_string(rest_len, alnum_charset);

    return var_name_first_ch + var_name_rest;
}

std::string gen_regex_rest () {

    std::string rgx_rest = random_string(rand()%spaces_limit, spaces_charset) +
                           random_string(1, oper_sgn_charset) +
                           random_string(rand()%spaces_limit, spaces_charset) +
                           gen_var_name() +
                           random_string(rand()%spaces_limit, spaces_charset);

    return rgx_rest;
}

std::string regex_gen () {
    std::string total_rgx;
    
    total_rgx = random_string(rand()%spaces_limit, spaces_charset) + 
    gen_var_name();

    bool rest_number = rand() % rest_repeat_limit;
    for (size_t i = 0; i < rest_number; i++)
        total_rgx = total_rgx + gen_regex_rest();

    return total_rgx;    
}

void make_regex_data (size_t cnt) {
    std::ofstream file("matching_strings.data", 
                        std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        for (size_t i = 0; i < cnt; i++) {
            //file << "regex #" << i << ":";
            file << regex_gen() << std::endl;
        }
        file.close();
    } else std::cerr << "File error." << std::endl;
}