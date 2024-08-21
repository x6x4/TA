
#include <iostream>
#include <sstream>
#include <string>
#include <FlexLexer.h>
#include <vector>
#include "../check_string.h"


class CustomLexer : public yyFlexLexer {
public:
    std::vector<std::string> var_name_tokens;
    bool valid_string = false;

    // Constructor
    CustomLexer(std::istream& in, std::ostream& out) : yyFlexLexer(&in, &out) {}

    // Destructor
    ~CustomLexer() {
        // Do any necessary cleanup here if needed.
    }

    // Override the yylex function
    int yylex() override {
        int token = yyFlexLexer::yylex();
        if (token == 0) {
            valid_string = true; 
        }
        return token;
    }
};

// CheckString functor class
class FlexCheckString : public CheckString {
public:
    bool operator()(const std::string& str) {
        // First Pass: Check for string validity using regex_str
        std::istringstream tok_stream(str);
        CustomLexer* lexer = new CustomLexer(tok_stream, std::cout);
         (lexer->yylex());    
        bool result = lexer->valid_string; // Check if the entire string was consumed by regex_str
        delete lexer;

        // Second Pass: Extract var_name tokens if the string is valid
        /*if (result) {
            lexer = new CustomLexer(tok_stream, std::cout);
            while (lexer->yylex());
            // Access the extracted tokens
            var_name_tokens = lexer->var_name_tokens;
            delete lexer;
        } */

        return result;
    }

    // Access extracted tokens
    auto get_var_name_tokens() {
        return var_name_tokens;
    }

};

//  lexer не создавать каждый раз
//  lexer as a class field

/*bool check_string(const std::string& str) {
    
    bool result = 0;
    std::istringstream tok_stream (str);
    FlexLexer* lexer = new yyFlexLexer(&tok_stream, &std::cout);

    while (lexer->yylex());
    result = (*lexer->YYText() == '\0');

    delete lexer;

    if (result) {
        var_name_tokens.clear(); // Clear the vector for a new string
        valid_string = true; // Set the flag to indicate a valid string
        tok_stream.str(str); // Reset the stream for the second pass
        lexer = new yyFlexLexer(&tok_stream, &std::cout);
        while (lexer->yylex());
        delete lexer;
    } 

    return result;

    return result;
}*/

//  target include directories