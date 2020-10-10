#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[1001];
bool isVisited[1001];

void dfsGraph(int vertex) {
    isVisited[vertex] = true;

    cout << vertex << ' ';

    for (int adjacentVertex : adjacentVerticesOf[vertex]) {
        if (!isVisited[adjacentVertex]) dfsGraph(adjacentVertex);
    }
}

int main() {
    int numVertex;
    int numEdge;
    int startVertex;
    queue<int> bfsQueue;

    cin >> numVertex >> numEdge >> startVertex;

    for (int i = 0; i < numEdge; i++) {
        int fromVertex;
        int toVertex;

        cin >> fromVertex >> toVertex;

        adjacentVerticesOf[fromVertex].push_back(toVertex);
        adjacentVerticesOf[toVertex].push_back(fromVertex);
    }

    for (auto &adjacentVertices : adjacentVerticesOf) {
        sort(adjacentVertices.begin(), adjacentVertices.end());
    }

    dfsGraph(startVertex);
    memset(isVisited, false, sizeof(isVisited));

    cout << '\n';

    isVisited[startVertex] = true;

    bfsQueue.push(startVertex);

    while (!bfsQueue.empty()) {
        int toVisitVertex = bfsQueue.front();

        cout << toVisitVertex << ' ';

        bfsQueue.pop();

        for (int adjacentVertex : adjacentVerticesOf[toVisitVertex]) {
            if (!isVisited[adjacentVertex]) {
                isVisited[adjacentVertex] = true;

                bfsQueue.push(adjacentVertex);
            }
        }
    }

    cout << '\n';

    return 0;
}
