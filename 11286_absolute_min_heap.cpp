#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
    int value;
} Node;

bool operator<(Node a, Node b) {
    return abs(a.value) > abs(b.value) || (abs(a.value) == abs(b.value) && a.value > b.value);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numInstruction;
    priority_queue<Node> maxHeap;

    cin >> numInstruction;

    while (numInstruction-- > 0) {
        int instruction;

        cin >> instruction;

        if (instruction == 0 && !maxHeap.empty()) {
            cout << maxHeap.top().value << '\n';

            maxHeap.pop();
        } else if (instruction == 0) cout << 0 << '\n';
        else maxHeap.push({instruction});
    }

    return 0;
}
