#include "AppClass.h"
#include <cctype>
#include <cstddef>
#include <iostream>

AppClass::AppClass()
: _fsm(*this),
  isAcceptable(false)
{
#ifdef FSM_DEBUG
#ifdef CRTP
    setDebugFlag(true);
#else
    _fsm.setDebugFlag(true);
#endif
#endif
}

bool SmcCheckString::operator()(const std::string &theString)
{
    if (theString.empty()) return false;

    _fsm.enterStartState();
    _fsm.to_expr_start();
    size_t char_num = 0;
    std::string spaces = " \t\f\v";
    std::string name;

    for (; theString[char_num] != '\0'; _fsm.to_expr_start()) {

        while (spaces.find(theString[char_num]) != std::string::npos) char_num++;
    
        if (isalpha(theString[char_num]) || theString[char_num] == '!') {
            _fsm.to_var_prefix();
            if (theString[++char_num] == '\0') break;
        }
        else break;
        

        size_t lim_char_num = 15;
        size_t char_in_name = 1;
        _fsm.to_var_name();
        int char_num_prev = char_num;

        for (; isalnum(theString[char_num]) && char_in_name < lim_char_num + 1; char_in_name++) {        
            _fsm.within_var_name();
            char_num++;
        }

        name = theString.substr(char_num_prev, char_num - char_num_prev);
        
        while (spaces.find(theString[char_num]) != std::string::npos) char_num++;

        if (theString[char_num] == '\0') break;

        _fsm.to_sign();
        std::string signs = "&|^";

        if (signs.find(theString[char_num]) == std::string::npos) break;
        char_num++;
    }

    // end of string has been reached - send the EOS transition.
    _fsm.EOS();

    if (_fsm.is_Acceptable) addVar(name);

    return _fsm.is_Acceptable();
}

//  string_view - const char * & string   by value


