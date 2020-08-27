#include <iostream>

using namespace std;

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        string parentheses;
        string::iterator head;
        int parenthesisStack = 0;

        cin >> parentheses;

        head = parentheses.begin();

        while (*head != '\0') {
            if (*head == '(') parenthesisStack++;
            else if (parenthesisStack > 0) parenthesisStack--;
            else {
                parenthesisStack = -1;

                break;
            }

            head++;
        }

        cout << (parenthesisStack == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
