#include <cmath>
#include "stack.h"

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

void doOperation(stack<double>& numbers, stack<char>& operations)
{
	if((operations.top()=='m')||(operations.top()=='p'))
	{
		double currentNumber = numbers.top();
		numbers.pop();
		while((operations.top()=='m')||(operations.top()=='p'))
		{
			if((operations.top()=='m'))
    		{
    			currentNumber*=-1;
    		}
    		operations.pop();
		}
		numbers.push(currentNumber);
	}
	else
	{
		double currentNumber = numbers.top();
		numbers.pop();
		double previousNumber = numbers.top();
		numbers.pop();
		double result = operate(previousNumber, currentNumber, operations.top());
		numbers.push(result);
		operations.pop();
	}
	
}