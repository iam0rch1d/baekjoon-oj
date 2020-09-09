#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adjacentVertexes[10001];
int diameter;
int farthestVertex;

void dfs(int currentVertex, int previousVertex, int totalLength) {
    if (diameter < totalLength) {
        diameter = totalLength;
        farthestVertex = currentVertex;
    }

    for (pair<int, int> adjacentVertex : adjacentVertexes[currentVertex]) {
        if (previousVertex != adjacentVertex.first) {
            dfs(adjacentVertex.first, currentVertex, totalLength + adjacentVertex.second);
        }
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
        cin >> toVertex;
        cin >> edgeLength;

        adjacentVertexes[fromVertex].emplace_back(toVertex, edgeLength);
        adjacentVertexes[toVertex].emplace_back(fromVertex, edgeLength);
    }

    dfs(1, 0, 0);

    diameter = 0;

    dfs(farthestVertex, 0, 0);

    cout << diameter << endl;

    return 0;
}
