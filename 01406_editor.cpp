#include <iostream>
#include <deque>

using namespace std;

char initialString[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    char *head;
    int numInstruction;
    deque<char> preCursorChars;
    deque<char> postCursorChars;

    cin >> initialString >> numInstruction;

    head = initialString;

    while (*head != '\0') {
        preCursorChars.push_back(*head++);
    }

    while (numInstruction-- > 0) {
        char instruction;

        cin >> instruction;

        if (instruction == 'L' && !preCursorChars.empty()) {
            postCursorChars.push_front(preCursorChars.back());
            preCursorChars.pop_back();
        } else if (instruction == 'D' && !postCursorChars.empty()) {
            preCursorChars.push_back(postCursorChars.front());
            postCursorChars.pop_front();
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

    cout << '\n';

    return 0;
}
