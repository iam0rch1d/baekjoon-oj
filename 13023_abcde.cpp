#include <iostream>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[2000];
int isVisited[2000];

void dfsGraph(int currentVertex, int depth) {
    if (depth == 4) {
        cout << "1\n";

        exit(0);
    }

    isVisited[currentVertex] = true;

    for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
        if (!isVisited[adjacentVertex]) dfsGraph(adjacentVertex, depth + 1);
    }

    isVisited[currentVertex] = false;
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
        dfsGraph(i, 0);
    }

    cout << "0\n";

    return 0;
}
