#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vstr = vector<string>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

int dist[1000][1000];

int main() {
    int n;
    int m;
    int p;

    cin >> n >> m >> p;

    vi s(p + 1);

    FOR_(i, 1, p) cin >> s[i];

    vstr a(n);
    vector<queue<pii>> bfsVerticesOf(p + 1);
    vector<queue<pii>> bfsNextVerticesOf(p + 1);

    REP(i, n) {
        cin >> a[i];

        REP(j, m) if (a[i][j] >= '1' && a[i][j] <= '9') bfsVerticesOf[a[i][j] - '0'].emplace(i, j);
    }

    while (true) {
        bool isAllEmpty = true;

        FOR_(player, 1, p) {
            RESET(dist, 0);

            while (!bfsVerticesOf[player].empty()) {
                isAllEmpty = false;

                int y;
                int x;

                tie(y, x) = bfsVerticesOf[player].front();

                if (dist[y][x] == s[player]) bfsNextVerticesOf[player].emplace(y, x);

                bfsVerticesOf[player].pop();

                REP(i, 4) {
                    int ny = y + "1201"[i] - '1';
                    int nx = x + "0112"[i] - '1';

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] != '.') continue;

                    dist[ny][nx] = dist[y][x] + 1;

                    if (dist[ny][nx] <= s[player]) {
                        a[ny][nx] = (char) (player + '0');

                        bfsVerticesOf[player].emplace(ny, nx);
                    }
                }
            }

            bfsVerticesOf[player] = bfsNextVerticesOf[player];
            bfsNextVerticesOf[player] = queue<pii>();
        }

        if (isAllEmpty) break;
    }

    vi ans(p + 1, 0);

    REP(i, n) REP(j, m) if (a[i][j] >= '0' && a[i][j] <= '9') ans[a[i][j] - '0']++;

    FOR_(i, 1, p) PRINT(ans[i]);

    PRINTLN("");

    return 0;
}
