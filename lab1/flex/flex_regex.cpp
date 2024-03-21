
#include <iostream>
#include <sstream>
#include <string>
#include <FlexLexer.h>

//  lexer не создавать каждый раз
//  lexer as a class field

bool check_string(const std::string& str) {
    
    bool result = 0;
    std::istringstream tok_stream (str);
    FlexLexer* lexer = new yyFlexLexer(tok_stream, std::cout);

    while (lexer->yylex());
    result = (*lexer->YYText() == '\0');

    delete lexer;

    return result;
}

//  target include directories