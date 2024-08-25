#pragma once
#include "../check_string.h"
#include <sstream>
#include <FlexLexer.h>

extern CleverMapa mapa;

class FlexCheckString : public CheckString {
public:
    bool operator()(const std::string& str) override {
        std::istringstream tok_stream(str);
        auto lexer = new yyFlexLexer(&tok_stream, &std::cout);
        while (lexer->yylex());    
        bool result = (*lexer->YYText() == '\0');
        delete lexer;

        return result;
    }

    void print() override {
        ::mapa.print();
    }

};