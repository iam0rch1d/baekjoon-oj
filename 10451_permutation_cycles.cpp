#include <cstring>
#include <iostream>

using namespace std;

int adjacentVertices[1000];
int cycleNoOf[1000];

void dfsGraph(int vertex, int cycleNo) {
    if (cycleNoOf[vertex]) return;

    cycleNoOf[vertex] = cycleNo;

    dfsGraph(adjacentVertices[vertex], cycleNo);
}

int main() {
    int testcases;

    cin >> testcases;

    while (testcases--) {
        int n;
        int cycleCount = 0;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> adjacentVertices[i];

            adjacentVertices[i]--;
        }

        for (int i = 0; i < n; i++) {
            if (!cycleNoOf[i]) dfsGraph(i, ++cycleCount);
        }

        cout << cycleCount << '\n';

        memset(adjacentVertices, 0, sizeof(adjacentVertices));
        memset(cycleNoOf, 0, sizeof(cycleNoOf));
    }

    return 0;
}
