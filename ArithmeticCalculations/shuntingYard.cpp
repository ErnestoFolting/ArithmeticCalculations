#include <iostream>
#include <string>
#include "stack.h"
#include "operation.h"
#include "doOperations.h"
#include "inputAndTokens.h"

using namespace std;

double calculate(string str) {
    stack<double> numbers;
    stack<char> operations;
	replaceUnaryOperationsWithSymbols(str);
	cout<<str<<endl;
    while (str.length() != 0)
    {
        string currentToken = token(str);
    	if (currentToken.length()>=1 && isdigit(currentToken[0])) {
    		numbers.push(stof(currentToken));
    		doOperation(numbers, operations);
        }
        else {
            if (operations.empty()) {
                operations.push(currentToken[0]);
            }
            else {
                operation currentOperation(currentToken[0]);
                operation previousOperation(operations.top());
            	if((currentOperation.name=='m')||(currentOperation.name=='p'))
            	{
            		operations.push(currentOperation.name);
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
		                doOperation(numbers, operations);
			            if(!operations.empty()) previousOperation = operations.top();
				    }
					operations.pop();
            	}
                else
                {
	                while (currentOperation.priority <= previousOperation.priority &&  !(operations.empty()) &&(previousOperation.name!='('))
                    {
		                doOperation(numbers, operations);
                        if (!operations.empty()) previousOperation = operations.top();
				    }
					operations.push(currentToken[0]);
                }
            }
            
        }
    }
    while (!operations.empty()) {
        doOperation(numbers, operations);
    }
    return numbers.top();
}
