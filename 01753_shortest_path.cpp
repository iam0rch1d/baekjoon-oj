#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

struct Edge {
    int toVertex;
    int cost;
};

#define INF 100000000

vector<Edge> edgesOf[20000];
bool isVisited[20000];

int main() {
    int v;
    int e;
    int k;

    cin >> v >> e >> k;

    k--;

    REP(i, e) {
        int fromVertex;
        int toVertex;
        int cost;

        cin >> fromVertex >> toVertex >> cost;

        fromVertex--;
        toVertex--;

        edgesOf[fromVertex].push_back({toVertex, cost});
    }

    vi distances(v, INF);
    priority_queue<pii> dijkstraVertices;

    distances[k] = 0;

    dijkstraVertices.push({0, k});

    while (!dijkstraVertices.empty()) {
        int vertex = dijkstraVertices.top().S;

        dijkstraVertices.pop();

        if (isVisited[vertex]) continue;

        isVisited[vertex] = true;

        for (auto edge : edgesOf[vertex]) {
            int toVertex = edge.toVertex;
            int cost = edge.cost;

            if (chmin(distances[toVertex], distances[vertex] + cost)) {
                dijkstraVertices.push({-distances[toVertex], toVertex});
            }
        }
    }

    REP(i, v) {
        if (distances[i] == INF) PRINTLN("INF");
        else PRINTLN(distances[i]);
    }

    return 0;
}
