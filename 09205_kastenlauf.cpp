#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

template<typename T>
T manhattan(pair<T, T> a, pair<T, T> b) { return abs(b.F - a.F) + abs(b.S - a.S); }

#define INF 99999

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int n;

        cin >> n;

        vpii points(n + 2);

        for (pii &point : points) {
            cin >> point.F >> point.S;
        }

        vvi distances(n + 2, vi(n + 2, INF));

        REP(i, n + 2) {
            REP(j, n + 2) {
                int tempDistance = manhattan(points[i], points[j]);

                distances[i][j] = tempDistance > 1000 ? INF : tempDistance;
            }
        }

        REP(aux, n + 2) {
            REP(from, n + 2) {
                REP(to, n + 2) chmin(distances[from][to], distances[from][aux] + distances[aux][to]);
            }
        }

        PRINTLN(distances[0].back() == INF ? "sad" : "happy");
    }

    return 0;
}
