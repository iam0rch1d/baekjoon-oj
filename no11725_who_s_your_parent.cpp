#include <iostream>
#include <vector>

using namespace std;

vector<int> childVertices[100001];
int parentVertices[100001];

void dfs(int currentVertex) {
    for (int adjacentVertex : childVertices[currentVertex]) {
        if (adjacentVertex != parentVertices[currentVertex]) {
            parentVertices[adjacentVertex] = currentVertex;

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

        childVertices[fromVertex].push_back(toVertex);
        childVertices[toVertex].push_back(fromVertex);
    }

    dfs(1);

    for (int i = 2; i <= numVertex; i++) {
        cout << parentVertices[i] << "\n";
    }

    return 0;
}
