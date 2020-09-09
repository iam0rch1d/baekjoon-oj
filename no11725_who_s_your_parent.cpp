#include <iostream>
#include <vector>

using namespace std;

vector<int> adjacentVertexes[100001];
int parentVertexes[100001];

void dfs(int currentVertex) {
    for (int adjacentVertex : adjacentVertexes[currentNode]) {
        if (adjacentVertex != parentVertexes[currentNode]) {
            parentVertexes[adjacentVertex] = currentNode;

            dfs(adjacentVertex);
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

        adjacentVertexes[fromVertex].push_back(toVertex);
        adjacentVertexes[toVertex].push_back(fromVertex);
    }

    dfs(1);

    for (int i = 2; i <= numVertex; i++) {
        cout << parentVertexes[i] << "\n";
    }

    return 0;
}
