#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum State {
    VISITED = 1,
    CYCLIC
};

vector<int> adjacentVerticesOf[3001];
int states[3001];
int dist[3001];

/**
 * @return [-1]: Non-cyclic / [0]: Unidentified / [1~]: Vertex at which the cycle begins
 */
int dfs(int currentVertex, int prevVertex) {
    if (states[currentVertex] == VISITED) return currentVertex;

    states[currentVertex] = VISITED;

    for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
        if (adjacentVertex == prevVertex) continue;

        int cycleStartVertex = dfs(adjacentVertex, currentVertex);

        if (cycleStartVertex == -1) return -1;
        else if (cycleStartVertex >= 1) {
            states[currentVertex] = CYCLIC;

            return currentVertex == cycleStartVertex ? -1 : cycleStartVertex;
        }
    }

    return 0;
}

int main() {
    int n;
    queue<int> bfsVertices;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int fromVertex;
        int toVertex;

        cin >> fromVertex >> toVertex;

        adjacentVerticesOf[fromVertex].push_back(toVertex);
        adjacentVerticesOf[toVertex].push_back(fromVertex);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        if (states[i] == CYCLIC) bfsVertices.push(i);
        else dist[i] = -1;
    }

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (dist[adjacentVertex] == -1) {
                dist[adjacentVertex] = dist[currentVertex] + 1;

                bfsVertices.push(adjacentVertex);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }

    cout << '\n';

    return 0;
}
