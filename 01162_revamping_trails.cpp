#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;
using pil = pair<int, ll>;
using vb = vector<bool>;
using vl = vector<ll>;
using vpil = vector<pil>;
using vvb = vector<vb>;
using vvl = vector<vl>;

#define F first
#define S second
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 567856785678

int main() {
    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    vpil edgesOf[10000];

    while (m--) {
        int fromVertex;
        int toVertex;
        ll cost;

        cin >> fromVertex >> toVertex >> cost;

        --fromVertex;
        --toVertex;

        edgesOf[fromVertex].emplace_back(toVertex, cost);
        edgesOf[toVertex].emplace_back(fromVertex, cost);
    }

    vvl d(n, vl(k + 1, INF));
    vvb isVisited(n, vb(k + 1, false));
    priority_queue<tuple<ll, int, int>> dijkstraVertices;

    d[0][0] = 0;

    dijkstraVertices.emplace(0, 0, 0);

    while (!dijkstraVertices.empty()) {
        ll distance;
        int vertex;
        int revamps;

        tie(distance, vertex, revamps) = dijkstraVertices.top();

        dijkstraVertices.pop();

        if (isVisited[vertex][revamps]) continue;

        isVisited[vertex][revamps] = true;

        for (pil edge : edgesOf[vertex]) {
            if (chmin(d[edge.F][revamps], d[vertex][revamps] + edge.S)) {
                dijkstraVertices.emplace(-d[edge.F][revamps], edge.F, revamps);
            }

            if (revamps < k && chmin(d[edge.F][revamps + 1], d[vertex][revamps])) {
                dijkstraVertices.emplace(-d[edge.F][revamps + 1], edge.F, revamps + 1);
            }
        }
    }

    ll ans = INF;

    FOR_(i, 0, k) if (isVisited[n - 1][i]) chmin(ans, d[n - 1][i]);

    PRINTLN(ans);

    return 0;
}
