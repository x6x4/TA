%{
using namespace std;
#include "/home/cracky/TA-lab1/lab1/check_string.h"
#include <algorithm>
CleverMapa mapa;
std::vector<std::string> tmp_tokens;

//  regex_str           ^{spaces}{var_name}({spaces}{oper_sgn}{spaces}{var_name}{spaces})*
%}


%option c++
%option yylineno

var_name_first_sym  (!|[[:alpha:]])
var_name_remainder  [[:alnum:]]{0,15}
var_name            {var_name_first_sym}{var_name_remainder}
spaces              ([ \t\r\f\v])*
oper_sgn            ([&|^])


%x SGN
%s NAME

%%      

{spaces}{var_name}{spaces}  { 
    tmp_tokens.push_back(yytext);
    BEGIN SGN;
} 

<NAME>{spaces}{var_name}{spaces}  {  
    tmp_tokens.push_back(yytext);
    BEGIN SGN;
} 

<NAME>. {
    tmp_tokens = std::vector<std::string>(); return 0;
}

<SGN>{spaces}{oper_sgn}  {
    BEGIN NAME;
} 
<SGN>. {
    tmp_tokens = std::vector<std::string>(); return 0;
} 

. {
    tmp_tokens = std::vector<std::string>(); return 0;
}


%%

int yywrap() {

    for (std::string str : tmp_tokens) {
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x) { return std::isspace(x); }), str.end());        
        mapa.addVar(str);
    }

    tmp_tokens = std::vector<std::string>();

    //mapa.print();
    return 1;
}
