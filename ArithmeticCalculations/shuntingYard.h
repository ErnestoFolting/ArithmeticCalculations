#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string getInput(int argc, char* argv[]);
string tocken(string& str);
int calculate(string str);