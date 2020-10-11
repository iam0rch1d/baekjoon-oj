#include <iostream>
#include <queue>

using namespace std;

vector<int> adjacentVerticesOf[1001];
bool isVisited[1001];

int main() {
    int numVertex;
    int numEdge;
    int connectedComponentCount = 0;
    queue<int> bfsQueue;

    cin >> numVertex >> numEdge;

    for (int i = 0; i < numEdge; i++) {
        int fromVertex;
        int toVertex;

        cin >> fromVertex >> toVertex;

        adjacentVerticesOf[fromVertex].push_back(toVertex);
        adjacentVerticesOf[toVertex].push_back(fromVertex);
    }

    while (true) {
        int startVertex = -1;

        for (int i = 1; i <= numVertex; i++) {
            if (!isVisited[i]) {
                startVertex = i;

                break;
            }
        }

        if (startVertex == -1) break;

        connectedComponentCount++;
        isVisited[startVertex] = true;

        bfsQueue.push(startVertex);

        while (!bfsQueue.empty()) {
            int toVisitVertex = bfsQueue.front();

            bfsQueue.pop();

            for (int adjacentVertex : adjacentVerticesOf[toVisitVertex]) {
                if (!isVisited[adjacentVertex]) {
                    isVisited[adjacentVertex] = true;

                    bfsQueue.push(adjacentVertex);
                }
            }
        }
    }

    cout << connectedComponentCount << '\n';

    return 0;
}
