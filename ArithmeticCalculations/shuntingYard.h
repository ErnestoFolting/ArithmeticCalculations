#pragma once
#include <string>

using namespace std;

string getInput(int argc, char* argv[]);
string tocken(string& str);
double calculate(string str);
double operate(double x1, double x2, char operation);