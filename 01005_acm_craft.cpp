#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define ALL(x) x.begin(), x.end()
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        int k;

        cin >> n >> k;

        vi costs(n + 1);

        FOR_(i, 1, n) cin >> costs[i];

        vvi adjacentVerticesOf(n + 1);
        vi indegrees(n + 1, 0);

        while (k--) {
            int x;
            int y;

            cin >> x >> y;

            adjacentVerticesOf[x].push_back(y);

            indegrees[y]++;
        }

        vi distances(n + 1, 0);
        queue<int> bfsVertices;

        FOR_(i, 1, n) {
            if (!indegrees[i]) {
                distances[i] = costs[i];

                bfsVertices.push(i);
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

        int w;

        cin >> w;

        PRINTLN(distances[w]);
    }

    return 0;
}
