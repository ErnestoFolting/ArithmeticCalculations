#include <iostream>
#include <iomanip>
#include "inputAndTokens.h"
#include "shuntingYard.h"

using namespace std;

int main(int argc, char *argv[])
{
    string str = getInput(argc, argv);
	int counterOpen=0, counterClose=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(') counterOpen++;
		else if(str[i]==')') counterClose++;
	}
	if(counterOpen!=counterClose) cout<<"Wrong number of open/closing braces"<<endl;
	else
	{
		double res = calculate(str);
		cout << "Result: " << fixed << setprecision(3) << res;
	}
}