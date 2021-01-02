#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int n;

    cin >> n;

    vvi distances(n, vi(n));

    REP(i, n) REP(j, n) cin >> distances[i][j];

    vvi isUsed(n, vi(n, true));

    REP(aux, n) {
        REP(from, n) {
            if (from == aux) continue;

            REP(to, n) {
                if (to == aux || to == from) continue;

                if (distances[from][to] > distances[from][aux] + distances[aux][to]) {
                    PRINTLN(-1);

                    return 0;
                }

                if (distances[from][to] == distances[from][aux] + distances[aux][to]) isUsed[to][from] = false;
            }
        }
    }

    int ans = 0;

    REP(i, n) REP(j, n) ans += isUsed[i][j] * distances[i][j];

    PRINTLN(ans / 2);

    return 0;
}
