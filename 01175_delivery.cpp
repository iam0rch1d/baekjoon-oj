#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using vstr = vector<string>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

int dist[50][50][4][4];

int main() {
    int n;
    int m;

    cin >> n >> m;

    vstr a(n);
    int sy;
    int sx;
    int cy0 = -1;
    int cx0;
    int cy1;
    int cx1;

    REP(i, n) {
        cin >> a[i];

        REP(j, m) {
            if (a[i][j] == 'S') tie(sy, sx) = {i, j};
            else if (a[i][j] == 'C') {
                if (cy0 == -1) tie(cy0, cx0) = {i, j};
                else tie(cy1, cx1) = {i, j};
            }
        }
    }

    RESET(dist, -1);

    queue<tuple<int, int, int, int>> bfsVertices;  // ({y, x, c, prevDirection})

    REP(i, 4) {
        dist[sy][sx][0][i] = 0;

        bfsVertices.emplace(sy, sx, 0, i);
    }

    while (!bfsVertices.empty()) {
        int y;
        int x;
        int c;
        int prevDirection;

        tie(y, x, c, prevDirection) = bfsVertices.front();

        if (c == 3) {
            PRINTLN(dist[y][x][c][prevDirection]);

            return 0;
        }

        bfsVertices.pop();

        REP(i, 4) {
            if (prevDirection == i) continue;

            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == '#') continue;

            int nc = c;

            nc |= (tie(ny, nx) == tie(cy1, cx1)) << 1;
            nc |= tie(ny, nx) == tie(cy0, cx0);

            if (dist[ny][nx][nc][i] != -1) continue;

            dist[ny][nx][nc][i] = dist[y][x][c][prevDirection] + 1;

            bfsVertices.emplace(ny, nx, nc, i);
        }
    }

    PRINTLN(-1);

    return 0;
}
