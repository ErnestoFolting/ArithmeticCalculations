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
        string currentToken = token(str);
        string copyStr = str;
        string nextTokenFromCopy = token(copyStr);
        string tokenAfterNextToken= token(copyStr);
        if ((currentToken == "(" || currentToken == "*" || currentToken == "/" || currentToken == "+") && nextTokenFromCopy == "-") {
            if (isdigit((tokenAfterNextToken)[0])) {
                int tempRes = stoi(tokenAfterNextToken)*(-1);
                numbers.push(tempRes);
                operations.push(currentToken[0]);
                token(str);
                token(str);
            }
        }
    	else if (currentToken.length()>=1 && isdigit(currentToken[0])) {
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
