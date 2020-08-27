#include <iostream>
#include <vector>

using namespace std;

enum Bracket {
    PARENTHESIS = 0,
    BRACKET
};

int main() {
    while (true) {
        string world;
        string::iterator head;
        vector<int> bracketStack;
        bool isValid = true;

        getline(cin, world);

        if (world == ".") break;

        head = world.begin();

        while (*head != '\0') {
            if (*head == '(') bracketStack.push_back(PARENTHESIS);
            else if (*head == '[') bracketStack.push_back(BRACKET);
            else if ((*head == ')' && !bracketStack.empty() && bracketStack[bracketStack.size() - 1] == PARENTHESIS)
            || (*head == ']' && !bracketStack.empty() && bracketStack[bracketStack.size() - 1] == BRACKET)) {
                bracketStack.pop_back();
            } else if (*head == ')' || *head == ']') {
                isValid = false;

                break;
            }

            head++;
        }

        cout << (isValid && bracketStack.empty() ? "yes" : "no") << endl;
    }

    return 0;
}
