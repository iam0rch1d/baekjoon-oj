#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    string postfix;
    string::iterator head;
    double operands[26];
    stack<double> operandStack;

    cin >> n >> postfix;

    head = postfix.begin();

    for (int i = 0; i < n; i++) {
        cin >> operands[i];
    }

    while (*head != '\0') {
        if (*head == '+') {
            double toUseFirst;
            double toUseSecond = operandStack.top();

            operandStack.pop();

            toUseFirst = operandStack.top();

            operandStack.pop();
            operandStack.push(toUseFirst + toUseSecond);
        } else if (*head == '-') {
            double toUseFirst;
            double toUseSecond = operandStack.top();

            operandStack.pop();

            toUseFirst = operandStack.top();

            operandStack.pop();
            operandStack.push(toUseFirst - toUseSecond);
        } else if (*head == '*') {
            double toUseFirst;
            double toUseSecond = operandStack.top();

            operandStack.pop();

            toUseFirst = operandStack.top();

            operandStack.pop();
            operandStack.push(toUseFirst * toUseSecond);
        } else if (*head == '/') {
            double toUseFirst;
            double toUseSecond = operandStack.top();

            operandStack.pop();

            toUseFirst = operandStack.top();

            operandStack.pop();
            operandStack.push(toUseFirst / toUseSecond);
        } else operandStack.push(operands[*head - 'A']);

        head++;
    }

    printf("%.2f\n", operandStack.top());

    return 0;
}
