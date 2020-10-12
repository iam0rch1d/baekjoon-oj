#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adjacentVerticesOf[10001];  // .first = <to-vertex>, .second = <edge length>
int diameter;
int farthestVertex;

void dfsTree(int currentVertex, int previousVertex, int totalLength) {
    if (diameter < totalLength) {
        diameter = totalLength;
        farthestVertex = currentVertex;
    }

    for (pair<int, int> adjacentVertex : adjacentVerticesOf[currentVertex]) {
        if (previousVertex != adjacentVertex.first) {
            dfsTree(adjacentVertex.first, currentVertex, totalLength + adjacentVertex.second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numVertex;

    cin >> numVertex;

    for (int i = 0; i < numVertex - 1; i++) {
        int fromVertex;
        int toVertex;
        int edgeLength;

        cin >> fromVertex >> toVertex >> edgeLength;

        adjacentVerticesOf[fromVertex].emplace_back(toVertex, edgeLength);
        adjacentVerticesOf[toVertex].emplace_back(fromVertex, edgeLength);
    }

    dfsTree(1, 0, 0);

    diameter = 0;

    dfsTree(farthestVertex, 0, 0);

    cout << diameter << '\n';

    return 0;
}
