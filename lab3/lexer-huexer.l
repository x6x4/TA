
%{
#include <iostream>
%}

%option noyywrap c++

spaces              ([ \t\r\f\v])*

ID                  (?i:[[:alpha:]]([[:alnum:]|_])*)
TYPE                (?i:"VAR"|"INT"|"BOOL"|"CELL")


BOOL_VALUE          (?i:"T"("rue")?|"F"("alse")?|"U"("ndef")?)

unsigned_value      ([[:digit:]])+
decimal_value       ("-")?{unsigned_value}
hex_value           ("-")?"0x"{unsigned_value}
regular_value       {decimal_value}|{hex_value}
special_value       (?i:"INF"|"-INF"|"NAN")
INT_VALUE           {regular_value}|{special_value}

CELL_VALUE          (?i:"EMPTY"|"WALL"|"BOX"|"EXIT"|"UNDEF")


param_decl      {TYPE}" "{ID}(", "{ID})*

bool_assign     (?i:"BOOL "){ID}" = "{BOOL_VALUE}
int_assign      (?i:"INT "){ID}" = "{INT_VALUE}
cell_assign     (?i:"CELL "){ID}" = "{CELL_VALUE}

assignment      {bool_assign}|{int_assign}|{cell_assign}

arith_val       {INT_VALUE}|{ID}
sum_up_arr      "#"{ID}
arith_expr      "-"{arith_val}|({arith_val}[+-])*{arith_val}|{sum_up_arr}


log_val         {BOOL_VALUE}|{ID}
comp_expr       {arith_expr}" "[<>=]" "{arith_expr}
mid_log_expr    {log_val}|{comp_expr}
xor_expr        ({mid_log_expr}"^")+{mid_log_expr}
log_expr        {mid_log_expr}|{xor_expr}

func_name       {ID}
func_call       {func_name}"("{param_decl}")"

expr            {arith_expr}|{log_expr}
statement       {spaces}({param_decl}|{assignment}|{func_call}|{expr})?{spaces}"\n"
statements      ({statement})*

func_sign       "fn "{func_name}" ("{param_decl}") "
block           "{"{spaces}"\n"{statements}{spaces}"}"{spaces}

func_def        {func_sign}{block}

while_loop      {spaces}"while "{log_expr}" "{block}("\n"{spaces}"finish "{block})?
branching       {spaces}"if "{log_expr}" "{block}("\n"{spaces}"eldef "{block})?("\n"{spaces}"elund "{block})?



%%


{branching}     { std::cout << "branching"; }
{while_loop}    { std::cout << "while_loop"; }
{xor_expr}      { std::cout << "xor_expr"; }
{comp_expr}     { std::cout << "comp_expr"; }
{sum_up_arr}    { std::cout << "sum_up_arr"; }
{arith_expr}    { std::cout << "arith_expr"; }
{param_decl}    { std::cout << "param_decl"; }
{assignment}    { std::cout << "ass"; }
{func_def}      { std::cout << "func_def"; }
{func_call}     { std::cout << "func_call"; }


%%
