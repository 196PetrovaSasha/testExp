#include <iostream>
#include <string>
using namespace std;

int evaluateExpression(const string& expression) {
    int result = 0;
    char operation = '+';
    int num = 0;

    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            num = num * 10 + (expression[i] - '0');
        }

        if (!isdigit(expression[i]) || i == expression.length() - 1) {
            if (operation == '+') {
                result += num;
            } else if (operation == '-') {
                result -= num;
            }

            operation = expression[i];
            num = 0;
        }
    }

    return result;
}

void findExpression(int total, int currentNum, string expression) {
    if (currentNum == 0) {
        if (evaluateExpression(expression) == total && expression[0] != '+') {
            cout << expression << "=" << total << endl;
        }
        return;
    }

    findExpression(total, currentNum - 1, to_string(currentNum) + expression);
    findExpression(total, currentNum - 1, "+" + to_string(currentNum) + expression);
    findExpression(total, currentNum - 1, "-" + to_string(currentNum) + expression);
}

int main() {
    findExpression(200, 9, "");
}