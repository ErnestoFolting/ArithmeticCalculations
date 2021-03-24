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
