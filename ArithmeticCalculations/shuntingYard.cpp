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
    while (str.length() != 0) {
        string temp = tocken(str);
        if (numbers.empty() && operations.empty() && temp[0] == '-') {
            string temp2 = tocken(str);
            if (isdigit(temp2[0])) {
                int tempRes = stoi(temp2) * (-1);
                numbers.push(tempRes);
            }
        }
        else if (temp.length()>=1 && isdigit(temp[0])) {
            numbers.push(stof(temp));
        }
        else {
            if (operations.empty()) {
                operations.push(temp[0]);
            }
            else {
                operation currentOperation(temp[0]);
                operation previousOperation(operations.top());
                if (currentOperation.name == '-' && previousOperation.name == '-') {
                    string copy = str;
                    int count = 2;
                    string temp = tocken(copy);
                    while (!isdigit(temp[0])) {
                        count++;
                        temp = tocken(copy);
                    }
                    int temp2 = stoi(temp);
                    if (count % 2) {
                        temp2 = stoi(temp) * (-1);
                    }
                    numbers.push(temp2);
                    operations.pop();
                    if (!numbers.empty()) {
                        operations.push('+');
                    }
                }
                if (currentOperation.name == '-' && (previousOperation.name == '(' || previousOperation.name == '+' || previousOperation.name == '*' || previousOperation.name == '/' || previousOperation.name == '^' )) {
                    string temp2 = tocken(str);
                    int tempRes = stoi(temp2) * (-1);
                    numbers.push(tempRes);
                }
                else if (previousOperation.name == '(' && currentOperation.name == ')') {
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
		                double currentNumber = numbers.top();
			            numbers.pop();
				        double previousNumber = numbers.top();
					    numbers.pop();
						double result = operate(previousNumber, currentNumber, previousOperation.name);
		                numbers.push(result);
		                operations.pop();
			            if(!operations.empty()) previousOperation = operations.top();
				    }
					operations.pop();
            	}
                else
                {
	                while (currentOperation.priority <= previousOperation.priority &&  !(operations.empty()))
                    {
		                double currentNumber = numbers.top();
			            numbers.pop();
				        double previousNumber = numbers.top();
					    numbers.pop();
						double result = operate(previousNumber, currentNumber, previousOperation.name);
		                numbers.push(result);
		                operations.pop();
			            if(!operations.empty()) previousOperation = operations.top();
				    }
					operations.push(temp[0]);
                }
            }
            
        }
    }
    while (!operations.empty()) {
        double currentNumber = numbers.top();
        numbers.pop();
        double previousNumber = numbers.top();
        numbers.pop();
        double result = operate(previousNumber, currentNumber, operations.top());
        numbers.push(result);
        operations.pop();
    }
    return numbers.top();
}
