
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>


size_t spaces_limit = 2;
size_t cnt = 1000;


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
        const size_t max_index = (charset.size());
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

std::string regex_gen (std::size_t str_length) {
    std::string total_rgx;
    
    total_rgx = random_string(rand()%spaces_limit, spaces_charset) + 
    gen_var_name();

    auto prev = total_rgx;

    while (total_rgx.length() < str_length) {
        prev = total_rgx;
        total_rgx = total_rgx + gen_regex_rest();
    }

    return total_rgx;    
}

#include "../check_string.h"  //  target include dirs
#include "../std_regex/std_regex.h"

std::string shit_gen (std::size_t str_length) {

    StdCheckString checker;

    std::string str(str_length,0);
    std::size_t print_ch_start = 32;
    std::size_t print_char_end = 126;

    do {
        for (size_t i = 0; i < str_length; i++) {
            str[i] = rand() % (print_char_end-print_ch_start+1) 
            + print_ch_start;
        }
    } while (checker(str));

    return str;
}

void make_regex_data (std::size_t str_length) {
    std::string filename = "./data/match" + std::to_string(str_length) + ".data";
    std::ofstream file(filename, 
                        std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        for (size_t i = 0; i < cnt; i++) {
            file << regex_gen(str_length) << '\n';
        }
        file.close();
    } else std::cerr << "File error." << std::endl;
}

void make_shit_data (std::size_t _length) {
    //  std::filesystem
    std::string filename = "./data/unmatch" + std::to_string(_length) + ".data";
    std::ofstream file(filename, 
                        std::ios::out | std::ios::trunc);
    if (file.is_open()) {
        for (size_t i = 0; i < cnt; i++) {
            file << shit_gen(_length) << '\n';
        }
        file.close();
    } else std::cerr << "File error." << std::endl;
}