#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[20001];
int colors[20001];

bool dfsBipartiteGraph(int currentVertex, int color) {
    colors[currentVertex] = color;

    return none_of(adjacentVerticesOf[currentVertex].begin(),
                   adjacentVerticesOf[currentVertex].end(),
                   [color, currentVertex](int adjacentVertex) {
                       return (colors[adjacentVertex] == 0 && !dfsBipartiteGraph(adjacentVertex, 3 - color))
                              || (colors[adjacentVertex] == colors[currentVertex]);
                   });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        int numVertex;
        int numEdge;
        bool isBipartite = true;

        cin >> numVertex >> numEdge;

        for (int i = 0; i < numEdge; i++) {
            int fromVertex;
            int toVertex;

            cin >> fromVertex >> toVertex;

            adjacentVerticesOf[fromVertex].push_back(toVertex);
            adjacentVerticesOf[toVertex].push_back(fromVertex);
        }

        for (int i = 1; i <= numVertex; i++) {
            if (colors[i] == 0 && !dfsBipartiteGraph(i, 1)) {
                isBipartite = false;

                break;
            }
        }

        cout << (isBipartite ? "YES\n" : "NO\n");

        for (int i = 1; i <= numVertex; i++) {
            adjacentVerticesOf[i].clear();
        }

        memset(colors, 0, sizeof(colors));
    }

    return 0;
}
