#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<int> verticesDirectedBy[100];

void bfsGraph(int startVertex) {
    vector<int> isVisited(n, false);
    queue<int> bfsVertices;

    bfsVertices.push(startVertex);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (int directingVertex : verticesDirectedBy[currentVertex]) {
            if (!isVisited[directingVertex]) {
                isVisited[directingVertex] = true;

                bfsVertices.push(directingVertex);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << isVisited[i] << ' ';
    }

    cout << '\n';
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int isDirecting;

            cin >> isDirecting;

            if (isDirecting) verticesDirectedBy[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++) {
        bfsGraph(i);
    }

    return 0;
}
