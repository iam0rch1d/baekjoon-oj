#include <iostream>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[2000];
int isVisited[2000];

void dfsRelation(int vertex, int depth) {
    if (depth == 4) {
        cout << "1\n";

        exit(0);
    }

    isVisited[vertex] = true;

    for (int adjacentVertex : adjacentVerticesOf[vertex]) {
        if (!isVisited[adjacentVertex]) dfsRelation(adjacentVertex, depth + 1);
    }

    isVisited[vertex] = false;
}

int main() {
    int n;
    int m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int fromVertex;
        int toVertex;

        cin >> fromVertex >> toVertex;

        adjacentVerticesOf[fromVertex].push_back(toVertex);
        adjacentVerticesOf[toVertex].push_back(fromVertex);
    }

    for (int i = 0; i < n; i++) {
        dfsRelation(i, 0);
    }

    cout << "0\n";

    return 0;
}
