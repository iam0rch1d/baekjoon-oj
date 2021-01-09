#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pbb = pair<bool, bool>;
using vi = vector<int>;
using vstr = vector<string>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

int dist[10][10][10][10];

int main() {
    int n;
    int m;

    cin >> n >> m;

    vstr a(n);
    int ryStart;
    int rxStart;
    int byStart;
    int bxStart;

    REP(i, n) {
        cin >> a[i];

        REP(j, m) {
            if (a[i][j] == 'R') {
                tie(ryStart, rxStart) = {i, j};
                a[i][j] = '.';
            } else if (a[i][j] == 'B') {
                tie(byStart, bxStart) = {i, j};
                a[i][j] = '.';
            }
        }
    }

    // (<is moved>, <is in hole>)
    auto roll = [&](vstr &a, int &y, int &x, int direction) -> pbb {
        if (a[y][x] == '.') return {false, false};

        bool retF = false;

        while (true) {
            int ny = y + "1210"[direction] - '1';
            int nx = x + "0121"[direction] - '1';

            if (a[ny][nx] == '#' || a[ny][nx] == 'R' || a[ny][nx] == 'B') return {retF, false};
            else if (a[ny][nx] == '.') {
                swap(a[y][x], a[ny][nx]);
                tie(y, x) = {ny, nx};
                retF = true;
            } else if (a[ny][nx] == 'O') {
                a[y][x] = '.';

                return {true, true};
            }
        }
    };

    // (<is red in hole>, <is blue in hole>)
    auto tilt = [&](vstr a, int &ry, int &rx, int &by, int &bx, int direction) -> pbb {
        a[ry][rx] = 'R';
        a[by][bx] = 'B';

        pbb ret{false, false};

        while (true) {
            pbb redStates = roll(a, ry, rx, direction);
            pbb blueStates = roll(a, by, bx, direction);

            if (!redStates.F && !blueStates.F) return ret;

            if (redStates.S) ret.F = true;

            if (blueStates.S) ret.S = true;
        }
    };

    RESET(dist, -1);

    dist[ryStart][rxStart][byStart][bxStart] = 0;

    queue<tuple<int, int, int, int>> bfsVertices;
    bool isFound = false;
    int ans = -1;

    bfsVertices.emplace(ryStart, rxStart, byStart, bxStart);

    while (!bfsVertices.empty()) {
        int ry;
        int rx;
        int by;
        int bx;

        tie(ry, rx, by, bx) = bfsVertices.front();

        bfsVertices.pop();

        REP(i, 4) {
            int nry = ry;
            int nrx = rx;
            int nby = by;
            int nbx = bx;

            pbb holeStates = tilt(a, nry, nrx, nby, nbx, i);

            if (holeStates.S) continue;

            if (holeStates.F) {
                isFound = true;
                ans = dist[ry][rx][by][bx] + 1;

                break;
            }

            if (dist[nry][nrx][nby][nbx] != -1) continue;

            dist[nry][nrx][nby][nbx] = dist[ry][rx][by][bx] + 1;

            bfsVertices.emplace(nry, nrx, nby, nbx);
        }

        if (isFound) break;
    }

    PRINTLN(ans);

    return 0;
}
