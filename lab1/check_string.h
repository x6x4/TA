#pragma once
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//  checks if string matches regex
class CheckString {

public:
    virtual bool operator()(const std::string& str) = 0; 

    void addVar(const std::string& name) {
        auto it = var_name_tokens.find(name);
        if (it != var_name_tokens.end())
            var_name_tokens[name]++;
        else 
            var_name_tokens[name] = 1;
    }

    void print() {
        std::ofstream myfile;
        myfile.open("/home/cracky/TA-lab1/lab1/stat.txt");
        if (myfile.is_open()) {
            for (auto e : var_name_tokens) {
                std::cout << e.first << ' ' << e.second << '\n';
            }
        }
        myfile.close();
    }

protected:
    std::map<std::string, int> var_name_tokens; // Store extracted var_name tokens
};