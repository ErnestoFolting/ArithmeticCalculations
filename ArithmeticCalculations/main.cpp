#include <iostream>
#include "stack.h"
#include "shuntingYard.h"

int main(int argc, char *argv[])
{
    string str = getInput(argc, argv);
    cout << "str:" << str << endl;
    double res = calculate(str);
    cout << "Result: " << res;
}