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
	int bracketSign=1;
	string copyStr=str;
	string currentCopyToken=token(copyStr);
	string nextCopyToken=token(copyStr);
	if((currentCopyToken=="-")&&(isdigit(nextCopyToken[0])))
    {
    	numbers.push(-1*stof(nextCopyToken));
    	token(str);
		token(str);
    }
    else if((currentCopyToken=="-")&&(nextCopyToken=="("))
	{
		bracketSign*=-1;
    	token(str);
	}
    while (str.length() != 0)
    {
    	string currentToken = token(str);
    	copyStr=str;
		currentCopyToken=token(copyStr);
		nextCopyToken=token(copyStr);
    	if((currentToken=="(")&&(currentCopyToken=="-")&&(nextCopyToken=="("))
    	{
    		bracketSign*=-1;
    		token(str);
    	}
        else if((currentToken=="(")&&(currentCopyToken=="-")&&(isdigit(nextCopyToken[0])))
        {
	        operations.push(currentToken[0]);
        	double number=-1*stof(nextCopyToken);
        	numbers.push(number);
        	token(str);
        	token(str);
        	currentToken=token(str);	
        }
		if (currentToken.length()>=1 && isdigit(currentToken[0])) {
            numbers.push(stof(currentToken));
        }
        else {
            if (operations.empty()) {
                operations.push(currentToken[0]);
            }
            else {
                operation currentOperation(currentToken[0]);
                operation previousOperation(operations.top());
                if (previousOperation.name == '(' && currentOperation.name == ')') {
                    operations.pop();
                	double number=numbers.top();
                	numbers.pop();
                	numbers.push(number*bracketSign);
                	bracketSign=1;
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
                	double number=numbers.top();
                	numbers.pop();
                	numbers.push(number*bracketSign);
                	bracketSign=1;
            	}
                else
                {
	                while (currentOperation.priority <= previousOperation.priority &&  !(operations.empty()) &&(previousOperation.name!='('))
                    {
		                doBinaryOperation(numbers, operations, previousOperation.name);
                        if (!operations.empty()) previousOperation = operations.top();
				    }
					operations.push(currentToken[0]);
                }
            }
            
        }
    }
    while (!operations.empty()) {
        doBinaryOperation(numbers, operations, operations.top());
    }
    return numbers.top();
}
