#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

vi adjacentVerticesOf[32001];
int indegrees[32001];

int main() {
    int n;
    int m;

    cin >> n >> m;

    while (m--) {
        int a;
        int b;

        cin >> a >> b;

        adjacentVerticesOf[a].push_back(b);

        indegrees[b]++;
    }

    queue<int> bfsVertices;

    FOR_(i, 1, n) if (!indegrees[i]) bfsVertices.push(i);

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        PRINT(currentVertex);
        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            if (--indegrees[adjacentVertex] == 0) bfsVertices.push(adjacentVertex);
        }
    }

    PRINTLN("");

    return 0;
}
