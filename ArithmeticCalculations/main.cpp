#include <iostream>
#include <iomanip>
#include "shuntingYard.h"

int main(int argc, char *argv[])
{
    string str = getInput(argc, argv);
	cout<<str<<endl;
    double res = calculate(str);
    cout << "Result: " << fixed << setprecision(3) << res;
}