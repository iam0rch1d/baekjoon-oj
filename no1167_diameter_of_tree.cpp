#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool hasVisited[100001];
vector<pair<int, int>> childVertices[100001];
int diameter;
int farthestVertex;

void dfs(int currentVertex, int totalLength) {
    if (hasVisited[currentVertex]) return;

    hasVisited[currentVertex] = true;

    if (diameter < totalLength) {
        diameter = totalLength;
        farthestVertex = currentVertex;
    }

    for (pair<int, int> adjacentVertex : childVertices[currentVertex]) {
        dfs(adjacentVertex.first, totalLength + adjacentVertex.second);
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

            childVertices[fromVertex].emplace_back(toVertex, edgeLength);
            childVertices[toVertex].emplace_back(fromVertex, edgeLength);
        }
    }

    dfs(1, 0); // Find the farthest vertex from root

    diameter = 0;

    memset(hasVisited, false, sizeof(hasVisited));
    dfs(farthestVertex, 0); // Find the farthest vertex and the distance from 'the farthest vertex from root'

    cout << diameter << endl;

    return 0;
}