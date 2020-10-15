#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[100000];
bool isVisited[100000];
int parentOf[100000];
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
        int fromVertex;
        int toVertex;

        cin >> fromVertex >> toVertex;

        fromVertex--;
        toVertex--;

        adjacentVerticesOf[fromVertex].push_back(toVertex);
        adjacentVerticesOf[toVertex].push_back(fromVertex);
    }

    for (int i = 0; i < n; i++) {
        cin >> orders[i];

        orders[i]--;
    }

    if (orders[0] != 0) printZero();

    isVisited[0] = true;
    visitedVertexCount = 1;

    bfsOrders.push(0);

    for (int i = 0; i < n; i++) {
        if (bfsOrders.empty()) printZero();

        int currentOrder = bfsOrders.front();
        int childCount = 0;

        bfsOrders.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentOrder]) {
            if (!isVisited[adjacentVertex]) {
                parentOf[adjacentVertex] = currentOrder;
                childCount++;
            }
        }

        for (int j = 0; j < childCount; j++) {
            if (visitedVertexCount + j >= n || parentOf[orders[visitedVertexCount + j]] != currentOrder) printZero();

            bfsOrders.push(orders[visitedVertexCount + j]);
            isVisited[orders[visitedVertexCount + j]] = true;
        }

        visitedVertexCount += childCount;
    }

    cout << "1\n";

    return 0;
}
