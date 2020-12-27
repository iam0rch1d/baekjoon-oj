#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vll = vector<ll>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define INF 987654321

struct Edge {
    int fromVertex;
    int toVertex;
    int weight;
};

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        int m;
        int w;

        cin >> n >> m >> w;

        int edgesSize = 2 * m + w;

        vector<Edge> edges(edgesSize);

        REP(i, m) {
            cin >> edges[i].fromVertex >> edges[i].toVertex >> edges[i].weight;

            edges[m + i] = {edges[i].toVertex, edges[i].fromVertex, edges[i].weight};
        }

        FOR(i, 2 * m, edgesSize) {
            cin >> edges[i].fromVertex >> edges[i].toVertex >> edges[i].weight;

            edges[i].weight = -edges[i].weight;
        }

        vll distances(n + 1, 0);
        bool hasNegativeCycle = false;

        FOR_(i, 1, n) {
            for (Edge edge : edges) {
                int s = edge.fromVertex;
                int e = edge.toVertex;
                int t = edge.weight;

                if (distances[s] != INF && distances[e] > distances[s] + t) {
                    distances[e] = distances[s] + t;

                    if (i == n) hasNegativeCycle = true;
                }
            }
        }

        PRINTLN(hasNegativeCycle ? "YES" : "NO");
    }

    return 0;
}
