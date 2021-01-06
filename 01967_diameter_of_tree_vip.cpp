#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adjacentVerticesOf[10001];  // (<to-vertex>, <edge length>)
int diameter;
int farthestVertex;

void dfs(int vertex, int prevVertex, int totalLength) {
    if (diameter < totalLength) {
        diameter = totalLength;
        farthestVertex = vertex;
    }

    for (pair<int, int> adjacentVertex : adjacentVerticesOf[vertex]) {
        if (prevVertex != adjacentVertex.first) {
            dfs(adjacentVertex.first, vertex, totalLength + adjacentVertex.second);
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

    dfs(1, 0, 0);

    diameter = 0;

    dfs(farthestVertex, 0, 0);

    cout << diameter << '\n';

    return 0;
}
