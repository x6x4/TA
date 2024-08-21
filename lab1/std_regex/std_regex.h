#pragma once
#include "../check_string.h"
#include <regex>


class StdCheckString : public CheckString {
public:
    bool operator()(const std::string& str) override;
};