#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvi = vector<vi>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 987654321

vpii a1[20];
vpii a2[20];

int main() {
    int n;

    cin >> n;

    REP(i, n) {
        string temp;

        cin >> temp;

        REP(j, n) if (temp[j] != '.') a1[i].emplace_back(j, temp[j] - '0');
    }

    REP(i, n) {
        string temp;

        cin >> temp;

        REP(j, n) if (temp[j] != '.') a2[i].emplace_back(j, temp[j] - '0');
    }

    vvi d1(n, vi(n * 9 + 1, INF));
    priority_queue<tuple<int, int, int>> dijkstraVertices;  // (d1[v][w2], v, w2)
    vvb isVisited(n, vb(n * 9 + 1, false));

    d1[0][0] = 0;

    dijkstraVertices.push({0, 0, 0});

    while (!dijkstraVertices.empty()) {
        int cd1;
        int cv;
        int cw2;

        tie(cd1, cv, cw2) = dijkstraVertices.top();

        dijkstraVertices.pop();

        if (isVisited[cv][cw2]) continue;

        isVisited[cv][cw2] = true;

        REP(i, a1[cv].size()) {
            int nv = a1[cv][i].F;
            int nw2 = cw2 + a2[cv][i].S;

            if (nw2 <= n * 9 && chmin(d1[nv][nw2], d1[cv][cw2] + a1[cv][i].S)) {
                dijkstraVertices.push({-d1[nv][nw2], nv, nw2});
            }
        }
    }

    int ans = INF;

    FOR_(i, 1, n * 9) if (isVisited[1][i]) chmin(ans, i * d1[1][i]);

    PRINTLN(ans == INF ? -1 : ans);

    return 0;
}
