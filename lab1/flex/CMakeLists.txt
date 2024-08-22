find_package(FLEX REQUIRED)
add_compile_options(-Wno-register)
flex_target(lexer rgx_lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)

SET(LIB_NAME "flex_regex")
add_library (${LIB_NAME} ${LIB_NAME}.h ${FLEX_lexer_OUTPUTS}  ../check_string.h)
