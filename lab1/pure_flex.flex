
%option noyywrap c++
%option yylineno

var_name_first_sym (!|[[:alpha:]])
var_name_remainder [[:alnum:]]{0,15}
var_name {var_name_first_sym}{var_name_remainder}
spaces ([ \t\r\f\v])*
oper_sgn [&, |, ^]
regex_str ^{spaces}{var_name}({spaces}{oper_sgn}{spaces}{var_name}{spaces})*$

%%      
{regex_str} { std::cout << "ok" << std::endl;}
\n 
.     { std::cout << "err" << std::endl; return 0; }
%%

int main() {
    FlexLexer* lexer = new yyFlexLexer;
    while(lexer->yylex() != 0);
    delete lexer;
}
