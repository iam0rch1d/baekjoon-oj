#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[100000];
bool isVisited[100000];
vector<int> dfsOrders;

void printZero() {
    cout << "0\n";

    exit(0);
}

void dfs(int currentVertex) {
    isVisited[currentVertex] = true;

    dfsOrders.push_back(currentVertex);

    for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
        if (!isVisited[adjacentVertex]) dfs(adjacentVertex);
    }
}

int main() {
    int n;

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

    dfs(0);

    cout << (dfsOrders == orders) << '\n';

    return 0;
}
