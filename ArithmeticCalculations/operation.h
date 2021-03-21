#pragma once
#include <iostream>
using namespace std;
struct operation {
    int priority;
    char name;
    operation(const char x) {
        name = x;
        if (x == '-') {
            priority = 1;
        }
        else if (x == '+') {
            priority = 1;
        }else if (x == '*') {
            priority = 2;
        }else if (x == '/') {
            priority = 2;
        }
    }
};