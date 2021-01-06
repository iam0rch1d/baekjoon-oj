#include <cstring>
#include <iostream>

using namespace std;

int adjacentVertices[1000];
int cycleNoOf[1000];

void dfs(int vertex, int cycleNo) {
    if (cycleNoOf[vertex]) return;

    cycleNoOf[vertex] = cycleNo;

    dfs(adjacentVertices[vertex], cycleNo);
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        int cycleCount = 0;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> adjacentVertices[i];

            adjacentVertices[i]--;
        }

        for (int i = 0; i < n; i++) {
            if (!cycleNoOf[i]) dfs(i, ++cycleCount);
        }

        cout << cycleCount << '\n';

        memset(adjacentVertices, 0, sizeof(adjacentVertices));
        memset(cycleNoOf, 0, sizeof(cycleNoOf));
    }

    return 0;
}
