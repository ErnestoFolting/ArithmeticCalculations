#include "shuntingYard.h"
#include "stack.h"
#include "operation.h"

string getInput(int argc, char* argv[]) {
    string str;
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            str += argv[i][j];
        }
    }
    for (int i = 0; i < str.length(); i++) {
        cout << str[i] << endl;
    }
    cout << "Check" << endl;
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
    double res = 0;
    stack<double> numbers;
    stack<char> operations;
    while (str.length() != 0) {
        string temp = tocken(str);
        if (temp.length()>1 || temp.length() == 1 && isdigit(temp[0])) {
            numbers.push(stof(temp));
        }
        else {
            if (operations.empty()) {
                operations.push(temp[0]);
            }
            else {
                operation curOp(temp[0]);
                operation prevOp(operations.top());
                while (curOp.prior <= prevOp.prior || !(operations.empty())) {
                    double curNum = numbers.top();
                    numbers.pop();
                    double prevNum = numbers.top();
                    numbers.pop();
                    double res = operate(prevNum, curNum, prevOp.name);
                    numbers.push(res);
                    operations.pop();
                    if(!operations.empty()) operation prevOp(operations.top());
                }
            }
            operations.push(temp[0]);
        }
    }
    while (!operations.empty()) {
        cout << "Operation:" << operations.top() << endl;
        operations.pop();
    }
    return res;
}
