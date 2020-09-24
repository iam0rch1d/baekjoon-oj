#include <iostream>
#include <stack>

using namespace std;

int main() {
    int numOperand;
    string postfix;
    string::iterator head;
    double operands[26];
    stack<double> operandStack;

    cin >> numOperand >> postfix;

    head = postfix.begin();

    for (int i = 0; i < numOperand; i++) {
        cin >> operands[i];
    }

    while (*head != '\0') {
        switch (*head) {
            case '+': {
                double toUseFirst;
                double toUseSecond = operandStack.top();

                operandStack.pop();

                toUseFirst = operandStack.top();

                operandStack.pop();
                operandStack.push(toUseFirst + toUseSecond);

                break;
            }
            case '-': {
                double toUseFirst;
                double toUseSecond = operandStack.top();

                operandStack.pop();

                toUseFirst = operandStack.top();

                operandStack.pop();
                operandStack.push(toUseFirst - toUseSecond);

                break;
            }
            case '*': {
                double toUseFirst;
                double toUseSecond = operandStack.top();

                operandStack.pop();

                toUseFirst = operandStack.top();

                operandStack.pop();
                operandStack.push(toUseFirst * toUseSecond);

                break;
            }
            case '/': {
                double toUseFirst;
                double toUseSecond = operandStack.top();

                operandStack.pop();

                toUseFirst = operandStack.top();

                operandStack.pop();
                operandStack.push(toUseFirst / toUseSecond);

                break;
            }
            default: {
                operandStack.push(operands[*head - 'A']);

                break;
            }
        }

        head++;
    }

    printf("%.2f\n", operandStack.top());

    return 0;
}
