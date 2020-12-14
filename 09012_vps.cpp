#include <iostream>

using namespace std;

int main() {
    int t;

    cin >> t;

    while (t--) {
        string brackets;
        string::iterator head;
        int bracketStack = 0;

        cin >> brackets;

        head = brackets.begin();

        while (*head != '\0') {
            if (*head == '(') bracketStack++;
            else if (bracketStack > 0) bracketStack--;
            else {
                bracketStack = -1;

                break;
            }

            head++;
        }

        cout << (bracketStack == 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}
