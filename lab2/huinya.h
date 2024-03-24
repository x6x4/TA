#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstdlib>
#include <fmt/format.h>

/*
01001

0    1     2      3       4
0 -> 01 -> 010 -> 0100 -> 01001

0 (0) 1
0 (1) 0
1 (0) 1
1 (1) 2
2 (0) 3
2 (1) 0
3 (0) 4
3 (1) 2
4 (0) 1
4 (1) 5
5 (0) 5
5 (1) 5
*/


using State = std::size_t;

struct Token {
    void unfold ();
};

struct Transition {
    char label;
    State next; 

    friend std::ostream &operator<< (std::ostream &os, const Transition &kyk) {
        return os << kyk.label << ' ' << kyk.next << ' ';
    }
};


struct KYK_PARSER {

    std::multimap<State, Transition> state_table;
    State last_state = 0;
    
    std::string delims = "|*+";
    bool not_delim(char ch) { return delims.find(ch) == std::string::npos; }


    void make_graph () {
        std::ofstream outfile("graph.dot");
        if (!outfile.is_open()) {
            throw std::runtime_error("Error: Unable to create file.");
        }

        outfile << "digraph G {\n";  
        outfile << "\trankdir=LR;\n"; 
        outfile << "0 [fillcolor=\"green\", style=\"filled\"];";
    
        std::string str;
        for (const auto &entry : state_table) {
            outfile << fmt::format("\t{} -> {} [label=\"{}\"];\n", 
            entry.first, entry.second.next, entry.second.label);
        }

        outfile << "}\n";
        outfile.close();

        system("dot -Tpng graph.dot -o graph.png");
    }

    friend std::ostream &operator<< (std::ostream &os, const KYK_PARSER &kyk) {
        for (const auto &entry : kyk.state_table) {
            os << entry.first << ' ' << entry.second << '\n';
        }
        return os;
    }


    //  returns end state of the chain
    void concat_chain (char* &ptr, State &cur_state, State entrypoint) {

        bool first_it = 1;

        for (char cur_char = 0; *ptr && not_delim(cur_char = *ptr);
            ptr++, cur_state++) {

            if (first_it) {
                state_table.insert({entrypoint, {cur_char, cur_state+1}});
                first_it = 0;
            }
            else state_table.insert({cur_state, {cur_char, cur_state + 1}});
        }
    }

    /*
            abc|de|fg
            012345678
    */

    bool make_chain (char* &ptr, State &entrypoint, State &endpoint) {

        static bool closure = 0;
        static bool binary_expr_end = 0;

        if (closure) {
            state_table.find(--last_state)->second.next = entrypoint;
            closure = 0;
        }

        State start_state = last_state;
        concat_chain(ptr, last_state, entrypoint);
        std::cout << endpoint << std::endl;
        std::cout << last_state << std::endl;
        char oper_sign = *ptr;

        if (binary_expr_end) {
            state_table.find(--last_state)->second.next = endpoint;
            binary_expr_end = 0;
        }

        switch (oper_sign) {

            case '\0':
                return 0;

            case '|':

                //  remember first endpoint
                if (!endpoint) {
                    entrypoint = start_state; 
                    endpoint = last_state;
                }
                binary_expr_end = 1;
            break;

            case '*':
                if (!endpoint) { 
                    endpoint = start_state;
                }
                closure = 1;

            break;

            default:
                throw std::runtime_error ("huinya kakaya-to");
        }
        
        return 1;
    }
        
    int compile(std::string_view tok_str) {

        State entrypoint = 0;
        State endpoint = 0;
        char *str_ptr = const_cast<char*>(tok_str.data());
        
        while (make_chain(str_ptr, entrypoint, endpoint)) {str_ptr++;}
        
        return 1;
    }
};


