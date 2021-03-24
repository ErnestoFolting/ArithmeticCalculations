#include "shuntingYard.h"
#include "stack.h"
#include "operation.h"
#include <iostream>
#include <cmath>

string getInput(int argc, char* argv[]) {
    string str;
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            str += argv[i][j];
        }
    }
    return str;
}

string tocken(string& str) {
    int k = 0;
    string tock;
    while (isdigit(str[k])) {
        k++;
    }
    if (k == 0) {
        tock = str.substr(0, 1);
        str.erase(0, 1);
    }
    else {
        tock = str.substr(0, k);
        str.erase(0, k);
    }
    return tock;
}

void doBinaryOperation(stack<double>& numbers, stack<char>& operations, char operation)
{
	double currentNumber = numbers.top();
    numbers.pop();
    double previousNumber = numbers.top();
    numbers.pop();
	double result = operate(previousNumber, currentNumber, operation);
	numbers.push(result);
	operations.pop();
}

double operate(double x1, double x2, char operation ) {
	switch(operation)
	{
    case '+':
        return x1 + x2;
	case '-':
        return x1 - x2;
	case '*':
        return x1*x2;
	case '/':
        return x1/x2;
	case '^':
        return pow(x1, x2);
	}
}

double calculate(string str) {
    stack<double> numbers;
    stack<char> operations;
	for(int i=0;i<static_cast<int>(str.length())-1;i++)
	{
        if((str[i]=='(')&&(str[i+1]=='-'))
	    {
		    str.insert(i+1, "0");
	    }
	}
	if(str[0]=='-')
	{
		str='0'+str;
	}
    while (str.length() != 0)
    {
        string currentTocken = tocken(str);
        string copyStr = str;
        string nextTockenFromCopy = tocken(copyStr);
        string tockenAfterNextTocken= tocken(copyStr);
        if ((currentTocken == "(" || currentTocken == "*" || currentTocken == "/" || currentTocken == "+") && nextTockenFromCopy == "-") {
            if (isdigit((tockenAfterNextTocken)[0])) {
                int tempRes = stoi(tockenAfterNextTocken)*(-1);
                numbers.push(tempRes);
                operations.push(currentTocken[0]);
                tocken(str);
                tocken(str);
            }
        }
    	else if (currentTocken.length()>=1 && isdigit(currentTocken[0])) {
            numbers.push(stof(currentTocken));
        }
        else {
            if (operations.empty()) {
                operations.push(currentTocken[0]);
            }
            else {
                operation currentOperation(currentTocken[0]);
                operation previousOperation(operations.top());
                if (previousOperation.name == '(' && currentOperation.name == ')') {
                    operations.pop();
                }
                else if((currentOperation.name == '(')||(previousOperation.name == '('))
            	{
            		operations.push(currentOperation.name);
            	}
                else if(currentOperation.name==')')
            	{
            		while (previousOperation.name!='(')
                    {
		                doBinaryOperation(numbers, operations, previousOperation.name);
			            if(!operations.empty()) previousOperation = operations.top();
				    }
					operations.pop();
            	}
                else
                {
	                while (currentOperation.priority <= previousOperation.priority &&  !(operations.empty()) &&(previousOperation.name!='('))
                    {
		                doBinaryOperation(numbers, operations, previousOperation.name);
                        if (!operations.empty()) previousOperation = operations.top();
				    }
					operations.push(currentTocken[0]);
                }
            }
            
        }
    }
    while (!operations.empty()) {
        doBinaryOperation(numbers, operations, operations.top());
    }
    return numbers.top();
}
