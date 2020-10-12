#include <iostream>
#include <queue>

using namespace std;

vector<int> adjacentVerticesOf[1001];
bool isVisited[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numVertex;
    int numEdge;
    int connectedComponentCount = 0;
    queue<int> bfsVertices;

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

        bfsVertices.push(startVertex);

        while (!bfsVertices.empty()) {
            int toVisitVertex = bfsVertices.front();

            bfsVertices.pop();

            for (int adjacentVertex : adjacentVerticesOf[toVisitVertex]) {
                if (!isVisited[adjacentVertex]) {
                    isVisited[adjacentVertex] = true;

                    bfsVertices.push(adjacentVertex);
                }
            }
        }
    }

    cout << connectedComponentCount << '\n';

    return 0;
}
