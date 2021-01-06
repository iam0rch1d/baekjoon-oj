#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adjacentVerticesOf[101];
int dist[101];

int main() {
    int n;
    int a;
    int b;
    int m;
    queue<int> bfsVertices;

    cin >> n >> a >> b >> m;

    while (m--) {
        int x;
        int y;

        cin >> x >> y;

        adjacentVerticesOf[x].push_back(y);
        adjacentVerticesOf[y].push_back(x);
    }

    dist[a] = 1;

    bfsVertices.push(a);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        if (currentVertex == b) {
            cout << dist[b] - 1 << '\n';

            return 0;
        }

        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (!dist[adjacentVertex]) {
                dist[adjacentVertex] = dist[currentVertex] + 1;

                bfsVertices.push(adjacentVertex);
            }
        }
    }

    cout << "-1\n";

    return 0;
}
