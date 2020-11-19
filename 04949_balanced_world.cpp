#include <iostream>
#include <stack>

using namespace std;

enum Bracket {
    PARENTHESIS = 0,
    BRACKET
};

int main() {
    while (true) {
        string world;
        string::iterator head;
        stack<int> bracketStack;
        bool isValid = true;

        getline(cin, world);

        if (world == ".") break;

        head = world.begin();

        while (*head != '\0') {
            if (*head == '(') bracketStack.push(PARENTHESIS);
            else if (*head == '[') bracketStack.push(BRACKET);
            else if ((*head == ')' && !bracketStack.empty() && bracketStack.top() == PARENTHESIS)
                     || (*head == ']' && !bracketStack.empty() && bracketStack.top() == BRACKET)) {
                bracketStack.pop();
            } else if (*head == ')' || *head == ']') {
                isValid = false;

                break;
            }

            head++;
        }

        cout << (isValid && bracketStack.empty() ? "yes" : "no") << '\n';
    }

    return 0;
}
