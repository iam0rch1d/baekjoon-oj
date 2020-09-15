#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numInstruction;
    priority_queue<int> maxHeap;

    cin >> numInstruction;

    while (numInstruction-- > 0) {
        int instruction;

        cin >> instruction;

        if (instruction == 0 && !maxHeap.empty()) {
            cout << maxHeap.top() << "\n";

            maxHeap.pop();
        } else if (instruction == 0) cout << 0 << "\n";
        else maxHeap.push(instruction);
    }

    return 0;
}
