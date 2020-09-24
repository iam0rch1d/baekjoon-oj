#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void printReverseWord(stack<char> &reverseWord) {
    if (!reverseWord.empty()) {
        while (!reverseWord.empty()) {
            cout << reverseWord.top();

            reverseWord.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    bool isTagOpened = false;
    stack<char> reverseWord;

    getline(cin, s);

    s += ' ';

    for (char sChar : s) {
        if (sChar == '<') {
            printReverseWord(reverseWord);

            isTagOpened = true;
        } else if (sChar == '>') {
            cout << '>';

            isTagOpened = false;

            continue;
        }

        if (isTagOpened) cout << sChar;
        else if (sChar == ' ') {
            printReverseWord(reverseWord);

            cout << ' ';
        } else reverseWord.push(sChar);
    }

    cout << '\n';

    return 0;
}
