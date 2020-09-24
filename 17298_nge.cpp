#include <iostream>
#include <stack>

using namespace std;

int sequence[1000001];
int nge[1000001];

int main() {
    int sequenceSize;
    stack<int> ngeIndices;

    cin >> sequenceSize;

    ngeIndices.push(0);

    for (int i = 1; i <= sequenceSize; i++) {
        cin >> sequence[i];

        while (!ngeIndices.empty() && sequence[ngeIndices.top()] < sequence[i]) {
            nge[ngeIndices.top()] = sequence[i];

            ngeIndices.pop();
        }

        ngeIndices.push(i);
    }

    while (!ngeIndices.empty()) {
        nge[ngeIndices.top()] = -1;

        ngeIndices.pop();
    }

    for (int i = 1; i <= sequenceSize; i++) {
        cout << nge[i] << ' ';
    }

    cout << '\n';

    return 0;
}
