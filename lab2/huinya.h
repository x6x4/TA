#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

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
    char hui;
    State next; 

    friend std::ostream &operator<< (std::ostream &os, const Transition &kyk) {
        return os << '{' << kyk.hui << ' ' << kyk.next << '}';
    }
};

void make_new_states (std::size_t child_num, State par); 

struct KYK_PARSER {

    std::multimap<State, Transition> state_table;
    State last_state = 0;
    std::string delims = "|*+";

    friend std::ostream &operator<< (std::ostream &os, const KYK_PARSER &kyk) {
        for (const auto &entry : kyk.state_table) {
            os << entry.first << ' ' << entry.second << '\n';
        }
        return os;
    }

    size_t concat (const std::string &tok_str, size_t first, size_t entrypoint) {

        size_t cur_state = entrypoint;
        size_t next_state = last_state + 1;
        size_t buf_first = first;

        for (char cur_char = 0; 
            delims.find((cur_char = tok_str[first])) == std::string::npos 
            && first < tok_str.size(); first++) {
            
            state_table.insert({cur_state, {cur_char, next_state}});
            cur_state = next_state++;
        }
        last_state = cur_state;
        return first - buf_first;
    }
        
    int compile(const std::string &tok_str) {

        size_t entrypoint = 0;
        
        for (size_t cur_pos = 0; cur_pos < tok_str.size(); ) {
            
            cur_pos += concat(tok_str, cur_pos, entrypoint);

            char oper_sign = tok_str[cur_pos++];
            std::cout << oper_sign << '\n';
            if (oper_sign == '|') { cur_pos += concat(tok_str, cur_pos++, entrypoint); }
            //else if (oper_sign == '*')  {}
            //else if (oper_sign)
            //    throw std::runtime_error ("huinya kakaya-to");
        }
        
        return 1;
    }
};

struct KYK_DFA {

//  свертка в номер конечного состояния 

    void alternate (std::vector<Token> branching_tokens) {

        //  (x)|(y)|(z)

        /*
        n ((x)) n+1
        n ((y)) n+1

        <n, a>
        */
        
        //make_new_states(branching_tokens.size(), last_state);
        for (auto t : branching_tokens)
            t.unfold();
    }   

    void repeat (Token t) {

        //start (t_part1) middle_state 
        //middle_state (t_part2) start 
        /*
        0 (a) 1 (b) *2 (a) 1 

        0 (a) 1
        1 (b) 2
        2 (a) 1
        */
    }
};

