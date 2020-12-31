#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vpii = vector<pii>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define INF 987654321

int main() {
    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    vpii edgesOf[1000];

    while (m--) {
        int a;
        int b;
        int c;

        cin >> a >> b >> c;

        --a;
        --b;

        edgesOf[a].emplace_back(b, c);
    }

    vector<priority_queue<int>> distancesOf(n);
    priority_queue<pii> dijkstraVertices;

    distancesOf[0].push(0);

    dijkstraVertices.push({0, 0});

    while (!dijkstraVertices.empty()) {
        int distance;
        int vertex;

        tie(distance, vertex) = dijkstraVertices.top();
        distance = -distance;

        dijkstraVertices.pop();

        for (pii edge : edgesOf[vertex]) {
            if (distancesOf[edge.F].size() == k) {
                if (distance + edge.S < distancesOf[edge.F].top()) distancesOf[edge.F].pop();
                else continue;
            }

            distancesOf[edge.F].push(distance + edge.S);
            dijkstraVertices.push({-(distance + edge.S), edge.F});
        }
    }

    REP(i, n) PRINTLN(distancesOf[i].size() == k ? distancesOf[i].top() : -1);

    return 0;
}
