#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;

#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

vi adjacentVerticesOf[10001];
int indegrees[10001];

int main() {
    int n;

    cin >> n;

    vi costs(n + 1);
    vi distances(n + 1, 0);
    queue<int> bfsVertices;

    FOR_(i, 1, n) {
        cin >> costs[i] >> indegrees[i];

        if (!indegrees[i]) {
            distances[i] = costs[i];

            bfsVertices.push(i);
        }

        REP(j, indegrees[i]) {
            int pretask;

            cin >> pretask;

            adjacentVerticesOf[pretask].push_back(i);
        }
    }

    while (!bfsVertices.empty()) {
        int currentVertex = bfsVertices.front();

        bfsVertices.pop();

        for (int adjacentVertex : adjacentVerticesOf[currentVertex]) {
            chmax(distances[adjacentVertex], distances[currentVertex] + costs[adjacentVertex]);

            if (--indegrees[adjacentVertex] == 0) bfsVertices.push(adjacentVertex);
        }
    }

    PRINTLN(*max_element(ALL(distances)));

    return 0;
}
