#include "shuntingYard.h"
#include "stack.h"
#include "operation.h"
#include <iostream>

string getInput(int argc, char* argv[]) {
    string str;
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            str += argv[i][j];
        }
    }
    /*for (int i = 0; i < str.length(); i++) {
        cout << str[i] << endl;
    }
    cout << "Check" << endl;*/
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
    if (operation == '+') return x1 + x2;
    if (operation == '-') return x1 - x2;
    if (operation == '/') return x1 / x2;
    if (operation == '*') return x1 * x2;
}
double calculate(string str) {
    stack<double> numbers;
    stack<char> operations;
    while (str.length() != 0) {
        string temp = tocken(str);
        if (temp.length()>=1 && isdigit(temp[0])) {
            numbers.push(stof(temp));
        }
        else {
            if (operations.empty()) {
                operations.push(temp[0]);
            }
            else {
                operation curentOperation(temp[0]);
                operation previousOperation(operations.top());
                while (curentOperation.priority <= previousOperation.priority &&  !(operations.empty())) {
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
