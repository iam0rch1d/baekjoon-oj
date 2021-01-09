#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int dist[1001][1001];

int main() {
    int n;
    int m;

    cin >> n >> m;

    vvi a(n + 1, vi(m + 1, 0));
    vvi s(n + 1, vi(m + 1, 0));

    FOR_(i, 1, n) {
        FOR_(j, 1, m) {
            cin >> a[i][j];

            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] - a[i][j];
        }
    }

    int h;
    int w;
    int sr;
    int sc;
    int fr;
    int fc;
    queue<pii> bfsVertices;

    cin >> h >> w >> sr >> sc >> fr >> fc;

    dist[sr][sc] = 1;

    bfsVertices.emplace(sr, sc);

    auto sum = [&](int y1, int x1, int y2, int x2) {
        return s[y2][x2] - s[y1 - 1][x2] - s[y2][x1 - 1] + s[y1 - 1][x1 - 1];
    };

    while (!bfsVertices.empty()) {
        int y;
        int x;

        tie(y, x) = bfsVertices.front();

        if (y == fr && x == fc) {
            PRINTLN(dist[y][x] - 1);

            return 0;
        }

        bfsVertices.pop();

        REP(i, 4) {
            int ny1 = y + "1201"[i] - '1';
            int nx1 = x + "0112"[i] - '1';
            int ny2 = ny1 + h - 1;
            int nx2 = nx1 + w - 1;

            if (ny1 < 1 || ny2 > n || nx1 < 1 || nx2 > m || dist[ny1][nx1] || sum(ny1, nx1, ny2, nx2)) continue;

            dist[ny1][nx1] = dist[y][x] + 1;

            bfsVertices.emplace(ny1, nx1);
        }
    }

    PRINTLN(-1);

    return 0;
}
