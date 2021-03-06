#include <iostream>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[100001];
int parents[100001];

void dfsParent(int currentVertex) {
    for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
        if (adjacentVertex != parents[currentVertex]) {
            parents[adjacentVertex] = currentVertex;

            dfsParent(adjacentVertex);
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

        cin >> fromVertex >> toVertex;

        adjacentVerticesOf[fromVertex].push_back(toVertex);
        adjacentVerticesOf[toVertex].push_back(fromVertex);
    }

    dfsParent(1);

    for (int i = 2; i <= numVertex; i++) {
        cout << parents[i] << '\n';
    }

    return 0;
}
