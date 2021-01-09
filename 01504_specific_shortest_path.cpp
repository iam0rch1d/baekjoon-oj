#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vpii = vector<pii>;

#define F first
#define S second
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 123456789

int main() {
    int n;
    int e;

    cin >> n >> e;

    vpii edgesOf[801];

    while (e--) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        edgesOf[a].emplace_back(b, c);
        edgesOf[b].emplace_back(a, c);
    }

    int v1;
    int v2;

    cin >> v1 >> v2;

    auto dijkstra = [&](int startVertex) -> vi {
        vi d(n + 1, INF);
        vb isVisited(n + 1, false);
        priority_queue<pii> dijkstraVertices;

        d[startVertex] = 0;

        dijkstraVertices.emplace(0, startVertex);

        while (!dijkstraVertices.empty()) {
            int distance;
            int vertex;

            tie(distance, vertex) = dijkstraVertices.top();

            dijkstraVertices.pop();

            if (isVisited[vertex]) continue;

            isVisited[vertex] = true;

            for (pii edge : edgesOf[vertex]) {
                if (chmin(d[edge.F], d[vertex] + edge.S)) dijkstraVertices.emplace(-d[edge.F], edge.F);
            }
        }

        return d;
    };

    auto d1 = dijkstra(1);
    auto dv1 = dijkstra(v1);
    auto dv2 = dijkstra(v2);
    int ans = min(d1[v1] + dv1[v2] + dv2[n], d1[v2] + dv2[v1] + dv1[n]);

    PRINTLN(ans >= INF ? -1 : ans);

    return 0;
}
