#pragma once
#include <iostream>
using namespace std;
struct operation {
    int prior;
    char name;
    operation(const char x) {
        if (x == '-') {
            name = x;
            prior = 1;
        }
        else if (x == '+') {
            name = x;
            prior = 1;
        }else if (x == '*') {
            name = x;
            prior = 2;
        }else if (x == '/') {
            name = x;
            prior = 2;
        }
    }
};