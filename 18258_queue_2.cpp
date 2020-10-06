#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numInstruction;
    queue<int> queue;

    cin >> numInstruction;

    while (numInstruction-- > 0) {
        string instruction;

        cin >> instruction;

        if (instruction == "push") {
            int target;

            cin >> target;

            queue.push(target);
        } else if (instruction == "pop") {
            cout << (queue.empty() ? -1 : queue.front()) << '\n';

            if (!queue.empty()) queue.pop();
        } else if (instruction == "size") cout << queue.size() << '\n';
        else if (instruction == "empty") cout << (queue.empty() ? 1 : 0) << '\n';
        else if (instruction == "front") cout << (queue.empty() ? -1 : queue.front()) << '\n';
        else if (instruction == "back") cout << (queue.empty() ? -1 : queue.back()) << '\n';
    }

    return 0;
}
