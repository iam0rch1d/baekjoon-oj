#include <iostream>
#include <deque>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vstr = vector<string>;

#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

#define INF 10001

int h;
int w;

vvi bfsDoorOpens(vstr &map, int sy, int sx) {
    vvi ret(h + 2, vi(w + 2, INF));
    deque<pii> bfsPoints;

    ret[sy][sx] = 0;

    bfsPoints.push_front({sy, sx});

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop_front();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= h + 2 || nx < 0 || nx >= w + 2 || map[ny][nx] == '*' || ret[ny][nx] != INF) {
                continue;
            }

            ret[ny][nx] = ret[y][x] + (map[ny][nx] == '#');

            map[ny][nx] == '#' ? bfsPoints.emplace_back(ny, nx) : bfsPoints.emplace_front(ny, nx);
        }
    }

    return ret;
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int y1 = -1;
        int x1;
        int y2;
        int x2;
        int ans = INF;

        cin >> h >> w;

        vstr a(h + 2);

        a[0] = string(w + 2, '.');
        a[h + 1] = a[0];

        for (int i = 1; i <= h; i++) {
            cin >> a[i];

            a[i] = '.' + a[i] + '.';

            for (int j = 1; j <= w; j++) {
                if (a[i][j] == '$') (y1 == -1 ? tie(y1, x1) : tie(y2, x2)) = {i, j};
            }
        }

        auto doorOpensAt0 = bfsDoorOpens(a, 0, 0);
        auto doorOpensAt1 = bfsDoorOpens(a, y1, x1);
        auto doorOpensAt2 = bfsDoorOpens(a, y2, x2);

        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                if (a[i][j] == '*') continue;

                chmin(ans, doorOpensAt0[i][j] + doorOpensAt1[i][j] + doorOpensAt2[i][j] - (a[i][j] == '#' ? 2 : 0));
            }
        }

        PRINTLN(ans);
    }

    return 0;
}
