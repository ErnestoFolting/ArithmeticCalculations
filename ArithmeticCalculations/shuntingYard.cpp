#include "shuntingYard.h"
#include "stack.h"

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
int calculate(string str) {
    double res = 0;
    stack<double> numbers;
    stack<char> operations;
    while (str.length() != 0) {
        string temp = tocken(str);
        if (temp.length()>1) {
            numbers.push(stof(temp));
        }
        else if (temp.length() == 1 && isdigit(temp[0])) {
            numbers.push(stof(temp));
        }
        else {
            operations.push(temp[0]);
        }
    }
    return res;
}
