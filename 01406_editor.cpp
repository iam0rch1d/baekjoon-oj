#include <iostream>
#include <deque>

using namespace std;

char initialString[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numInstruction;
    deque<char> preCursorChars;
    deque<char> postCursorChars;

    cin >> initialString >> numInstruction;

    for (char initialChar : initialString) {
        if (initialChar == '\0') break;

        preCursorChars.push_back(initialChar);
    }

    while (numInstruction-- > 0) {
        char instruction;

        cin >> instruction;

        if (instruction == 'L' && !preCursorChars.empty()) {
            char toMove = preCursorChars.back();

            preCursorChars.pop_back();
            postCursorChars.push_front(toMove);
        } else if (instruction == 'D' && !postCursorChars.empty()) {
            char toMove = postCursorChars.front();

            postCursorChars.pop_front();
            preCursorChars.push_back(toMove);
        } else if (instruction == 'B' && !preCursorChars.empty()) preCursorChars.pop_back();
        else if (instruction == 'P') {
            char toAppend;

            cin >> toAppend;

            preCursorChars.push_back(toAppend);
        }
    }

    while (!preCursorChars.empty()) {
        cout << preCursorChars.front();

        preCursorChars.pop_front();
    }

    while (!postCursorChars.empty()) {
        cout << postCursorChars.front();
        postCursorChars.pop_front();
    }

    cout << "\n";

    return 0;
}
