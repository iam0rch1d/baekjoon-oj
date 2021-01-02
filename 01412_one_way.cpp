#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 987654321

int main() {
    int n;

    cin >> n;

    vvi d(n, vi(n, INF));

    REP(i, n) {
        string temp;

        cin >> temp;

        REP(j, n) if (temp[j] == 'Y') d[i][j] = 1;
    }

    REP(i, n) {
        REP(j, n) {
            if (d[i][j] == 1 && d[j][i] == 1) {
                d[i][j] = INF;
                d[j][i] = INF;
            }
        }
    }

    REP(aux, n) REP(from, n) REP(to, n) chmin(d[from][to], d[from][aux] + d[aux][to]);

    REP(i, n) {
        if (d[i][i] != INF) {
            PRINTLN("NO");

            return 0;
        }
    }

    PRINTLN("YES");

    return 0;
}
