#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vll = vector<ll>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define INF 1e9

struct Edge {
    int fromVertex;
    int toVertex;
    int weight;
};

int main() {
    int n;
    int m;

    cin >> n >> m;

    vector<Edge> edges(m);

    for (Edge &edge : edges) {
        cin >> edge.fromVertex >> edge.toVertex >> edge.weight;
    }

    vll distances(n + 1, INF);
    bool hasNegativeCycle = false;

    distances[1] = 0;

    FOR_(i, 1, n) {
        for (Edge edge : edges) {
            int a = edge.fromVertex;
            int b = edge.toVertex;
            int c = edge.weight;

            if (distances[a] != INF && distances[b] > distances[a] + c) {
                distances[b] = distances[a] + c;

                if (i == n) hasNegativeCycle = true;
            }
        }
    }

    if (hasNegativeCycle) PRINTLN(-1);
    else FOR_(i, 2, n) PRINTLN(distances[i] == INF ? -1 : distances[i]);

    return 0;
}
