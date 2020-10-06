#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numInstruction;
    deque<int> deque;

    cin >> numInstruction;

    while (numInstruction-- > 0) {
        string instruction;

        cin >> instruction;

        if (instruction == "push_front") {
            int target;

            cin >> target;

            deque.push_front(target);
        } else if (instruction == "push_back") {
            int target;

            cin >> target;

            deque.push_back(target);
        } else if (instruction == "pop_front") {
            cout << (deque.empty() ? -1 : deque.front()) << '\n';

            if (!deque.empty()) deque.pop_front();
        } else if (instruction == "pop_back") {
            cout << (deque.empty() ? -1 : deque.back()) << '\n';

            if (!deque.empty()) deque.pop_back();
        } else if (instruction == "size") cout << deque.size() << '\n';
        else if (instruction == "empty") cout << (deque.empty() ? 1 : 0) << '\n';
        else if (instruction == "front") cout << (deque.empty() ? -1 : deque.front()) << '\n';
        else if (instruction == "back") cout << (deque.empty() ? -1 : deque.back()) << '\n';
    }

    return 0;
}
