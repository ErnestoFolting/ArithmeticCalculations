#pragma once
#include <iostream>
using namespace std;
struct operation {
    int priority;
    char name;
    operation(const char x) {
        if (x == '-') {
            name = x;
            priority = 1;
        }
        else if (x == '+') {
            name = x;
            priority = 1;
        }else if (x == '*') {
            name = x;
            priority = 2;
        }else if (x == '/') {
            name = x;
            priority = 2;
        }
    }
};