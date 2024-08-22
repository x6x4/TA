#pragma once
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class CleverMapa {
    std::map<std::string, int> var_name_tokens;

public:

    CleverMapa() {
        std::ofstream myfile;
        myfile.open("/home/cracky/TA-lab1/lab1/stat.txt");
    }

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
            for (const auto &e : var_name_tokens) {
                myfile << e.first.c_str() << ' ' << e.second << std::endl;
            }
        }
        myfile.close();
    }
};

//  checks if string matches regex
class CheckString {

CleverMapa mapa;

public:
    virtual bool operator()(const std::string& str) = 0; 

    void addVar(const std::string& name) {
        mapa.addVar(name);
    }

    virtual void print() {
       mapa.print();
    }
};