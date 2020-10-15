#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[100000];
bool isVisited[100000];

void printZero() {
    cout << "0\n";

    exit(0);
}

int main() {
    int n;
    queue<int> bfsVertices;
    vector<int> bfsOrders;

    cin >> n;

    vector<int> orders(n);
    vector<int> orderOf(n);

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
        orderOf[orders[i]] = i;
    }

    if (orders[0] != 0) printZero();

    for (int i = 0; i < n; i++) {
        sort(adjacentVerticesOf[i].begin(),
             adjacentVerticesOf[i].end(),
             [&](int i, int j) { return orderOf[i] < orderOf[j]; });
    }

    isVisited[0] = true;

    bfsVertices.push(0);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsOrders.push_back(currentVertex);
        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (!isVisited[adjacentVertex]) {
                isVisited[adjacentVertex] = true;

                bfsVertices.push(adjacentVertex);
            }
        }
    }

    cout << (bfsOrders == orders) << '\n';

    return 0;
}
