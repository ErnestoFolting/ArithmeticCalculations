#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
string getInput(int argc, char* argv[]);
string tocken(string& str);
double calculate(string str);
double operate(double x1, double x2, char operation);