#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 100000000

struct Edge {
    int toVertex;
    int weight;
};

vector<Edge> edgesOf[100000];
bool isVisited[100000];

int main() {
    int n;
    int m;

    cin >> n >> m;

    REP(i, m) {
        int fromVertex;
        int toVertex;
        int weight;

        cin >> fromVertex >> toVertex >> weight;

        fromVertex--;
        toVertex--;

        edgesOf[fromVertex].push_back({toVertex, weight});
    }

    int startVertex;
    int finishVertex;

    cin >> startVertex >> finishVertex;

    startVertex--;
    finishVertex--;

    vi distances(n, INF);
    priority_queue<pii> dijkstraVertices;

    distances[startVertex] = 0;

    dijkstraVertices.push({0, startVertex});

    while (!dijkstraVertices.empty()) {
        int distance;
        int vertex;

        tie(distance, vertex) = dijkstraVertices.top();

        dijkstraVertices.pop();

        if (isVisited[vertex]) continue;

        isVisited[vertex] = true;

        for (auto edge : edgesOf[vertex]) {
            int toVertex = edge.toVertex;
            int weight = edge.weight;

            if (chmin(distances[toVertex], distances[vertex] + weight)) {
                dijkstraVertices.push({-distances[toVertex], toVertex});
            }
        }
    }

    PRINTLN(distances[finishVertex]);

    return 0;
}
