#include <iostream>
#include <set>
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

#define INF 100000000

struct Edge {
    int toVertex;
    int cost;
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
        int cost;

        cin >> fromVertex >> toVertex >> cost;

        fromVertex--;
        toVertex--;

        edgesOf[fromVertex].push_back({toVertex, cost});
    }

    int startVertex;
    int finishVertex;

    cin >> startVertex >> finishVertex;

    startVertex--;
    finishVertex--;

    vi distances(n, INF);
    set<pii> dijkstraVertices;

    distances[startVertex] = 0;

    dijkstraVertices.insert({0, startVertex});

    while (!dijkstraVertices.empty()) {
        int distance;
        int vertex;

        tie(distance, vertex) = *dijkstraVertices.begin();

        dijkstraVertices.erase(dijkstraVertices.begin());

        if (isVisited[vertex]) continue;

        isVisited[vertex] = true;

        for (auto edge : edgesOf[vertex]) {
            int toVertex = edge.toVertex;
            int cost = edge.cost;

            if (distances[toVertex] > distances[vertex] + cost) {
                if (distances[toVertex] != INF) {
                    dijkstraVertices.erase(dijkstraVertices.find({distances[toVertex], toVertex}));
                }

                distances[toVertex] = distances[vertex] + cost;

                dijkstraVertices.insert({distances[vertex] + cost, toVertex});
            }
        }
    }

    PRINTLN(distances[finishVertex]);

    return 0;
}
