#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct Vertex {
    vector<int> adjacents;
    bool isVisited{};
    int parent{};
} Vertex;

Vertex vertices[100000];
int orders[100000];

void printZero() {
    cout << "0\n";

    exit(0);
}

int main() {
    int n;
    int visitedVertexCount;
    queue<int> bfsOrders;

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int from;
        int to;

        cin >> from >> to;

        from--;
        to--;

        vertices[from].adjacents.push_back(to);
        vertices[to].adjacents.push_back(from);
    }

    for (int i = 0; i < n; i++) {
        cin >> orders[i];

        orders[i]--;
    }

    vertices[0].isVisited = true;
    visitedVertexCount = 1;

    bfsOrders.push(0);

    for (int i = 0; i < n; i++) {
        if (bfsOrders.empty()) printZero();

        int currentOrder = bfsOrders.front();

        if (currentOrder != orders[i]) printZero();

        int childCount = 0;

        bfsOrders.pop();

        for (int adjacent : vertices[currentOrder].adjacents) {
            if (!vertices[adjacent].isVisited) {
                vertices[adjacent].parent = currentOrder;
                childCount++;
            }
        }

        for (int j = 0; j < childCount; j++) {
            if (visitedVertexCount + j >= n || vertices[orders[visitedVertexCount + j]].parent != currentOrder) {
                printZero();
            }

            bfsOrders.push(orders[visitedVertexCount + j]);
            vertices[orders[visitedVertexCount + j]].isVisited = true;
        }

        visitedVertexCount += childCount;
    }

    cout << "1\n";

    return 0;
}
