
#include <FlexLexer.h>

int main() {
    FlexLexer* lexer = new yyFlexLexer;
    while(lexer->yylex() != 0);
    std::cout << std::endl;
    delete lexer;
}