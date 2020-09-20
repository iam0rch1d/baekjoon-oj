#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    string s;
    bool isForward = false;
    queue<char> forwardWord;
    stack<char> reverseWord;

    getline(cin, s);

    for (char &sChar : s) {
        if (sChar == '<') {
            if (!reverseWord.empty()) {
                while (!reverseWord.empty()) {
                    cout << reverseWord.top();

                    reverseWord.pop();
                }
            }

            isForward = true;
        } else if (sChar == '>') {
            while (!forwardWord.empty()) {
                cout << forwardWord.front();

                forwardWord.pop();
            }

            cout << '>';

            isForward = false;

            continue;
        }

        if (isForward) forwardWord.push(sChar);
        else if (sChar == ' ') {
            while (!reverseWord.empty()) {
                cout << reverseWord.top();

                reverseWord.pop();
            }

            cout << ' ';
        } else reverseWord.push(sChar);
    }

    if (!reverseWord.empty()) {
        while (!reverseWord.empty()) {
            cout << reverseWord.top();

            reverseWord.pop();
        }
    }

    cout << "\n";

    return 0;
}
