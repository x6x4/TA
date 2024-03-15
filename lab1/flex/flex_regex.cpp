
#include <iostream>
#include <sstream>
#include <string>
#include <FlexLexer.h>


bool check_string(const std::string& str) {
    
    bool result = 0;
    std::istringstream tok_stream (str);
    FlexLexer* lexer = new yyFlexLexer(tok_stream, std::cout);

    while (lexer->yylex());
    result = (*lexer->YYText() == '\0');

    delete lexer;

    return result;
}