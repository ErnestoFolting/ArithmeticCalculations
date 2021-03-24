#include <iostream>
#include <iomanip>
#include "inputAndTokens.h"
#include "shuntingYard.h"

using namespace std;

int main(int argc, char *argv[])
{
    string str = getInput(argc, argv);
    double res = calculate(str);
    cout << "Result: " << fixed << setprecision(3) << res;
}