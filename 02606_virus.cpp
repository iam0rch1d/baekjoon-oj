#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isVisited[101];

int main() {
    int numVertex;
    int numEdge;
    vector<int> adjacentVerticesOf[101];
    queue<int> bfsVertices;
    int infectionCount = 0;

    cin >> numVertex >> numEdge;

    while (numEdge-- > 0) {
        int fromVertex;
        int toVertex;

        cin >> fromVertex >> toVertex;

        adjacentVerticesOf[fromVertex].push_back(toVertex);
        adjacentVerticesOf[toVertex].push_back(fromVertex);
    }

    isVisited[1] = true;

    bfsVertices.push(1);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (!isVisited[adjacentVertex]) {
                isVisited[adjacentVertex] = true;

                bfsVertices.push(adjacentVertex);
            }
        }
    }

    for (int i = 2; i <= numVertex; i++) {
        infectionCount += isVisited[i];
    }

    cout << infectionCount << '\n';

    return 0;
}
