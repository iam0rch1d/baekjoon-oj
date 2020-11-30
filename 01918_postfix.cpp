#include <iostream>
#include <stack>

using namespace std;

int getPriority(char symbol) {
    if (symbol == '(') return 0;
    else if (symbol == '+' || symbol == '-') return 1;
    else return 2;
}

int main() {
    string infix;
    string::iterator head;
    stack<char> shuntingYard;
    string postfix;

    cin >> infix;

    head = infix.begin();

    while (*head != '\0') {
        if (*head >= 'A' && *head <= 'Z') postfix += *head;
        else if (*head == '(') shuntingYard.push(*head);
        else if (*head == ')') {
            while (!shuntingYard.empty()) {
                char symbol = shuntingYard.top();

                shuntingYard.pop();

                if (symbol == '(') break;

                postfix += symbol;
            }
        } else {
            while (!shuntingYard.empty() && getPriority(shuntingYard.top()) >= getPriority(*head)) {
                postfix += shuntingYard.top();

                shuntingYard.pop();
            }

            shuntingYard.push(*head);
        }

        head++;
    }

    while (!shuntingYard.empty()) {
        postfix += shuntingYard.top();

        shuntingYard.pop();
    }

    cout << postfix << '\n';

    return 0;
}
