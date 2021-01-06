#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adjacentVerticesOf[100001];  // (<to-vertex>, <edge length>)
bool isVisited[100001];
int diameter;
int farthestVertex;

void dfsTree(int currentVertex, int totalLength) {
    if (isVisited[currentVertex]) return;

    isVisited[currentVertex] = true;

    if (diameter < totalLength) {
        diameter = totalLength;
        farthestVertex = currentVertex;
    }

    for (pair<int, int> adjacentVertex : adjacentVerticesOf[currentVertex]) {
        dfsTree(adjacentVertex.first, totalLength + adjacentVertex.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numVertex;

    cin >> numVertex;

    for (int i = 0; i < numVertex; i++) {
        int fromVertex;
        int toVertex;
        int edgeLength;

        cin >> fromVertex;

        while (true) {
            cin >> toVertex;

            if (toVertex == -1) break;

            cin >> edgeLength;

            adjacentVerticesOf[fromVertex].emplace_back(toVertex, edgeLength);
            adjacentVerticesOf[toVertex].emplace_back(fromVertex, edgeLength);
        }
    }

    dfsTree(1, 0);  // Find the farthest vertex from root

    diameter = 0;

    memset(isVisited, false, sizeof(isVisited));
    dfsTree(farthestVertex, 0);  // Find the farthest vertex and the distance from 'the farthest vertex from root'

    cout << diameter << '\n';

    return 0;
}
