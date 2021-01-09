#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vstr = vector<string>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

bool vSwan[1500][1500];
bool vWater[1500][1500];

int main() {
    int r;
    int c;

    cin >> r >> c;

    vstr a(r);
    int y1 = -1;
    int x1;
    int y2;
    int x2;
    queue<pii> bfsSwan;
    queue<pii> bfsWater;

    REP(i, r) {
        cin >> a[i];

        REP(j, c) {
            if (a[i][j] == 'L') {
                if (y1 == -1) {
                    tie(y1, x1) = make_pair(i, j);
                    vSwan[y1][x1] = true;

                    bfsSwan.emplace(y1, x1);
                } else tie(y2, x2) = make_pair(i, j);

                a[i][j] = '.';
            }

            if (a[i][j] == '.') {
                vWater[i][j] = true;

                bfsWater.emplace(i, j);
            }
        }
    }

    int d = 0;

    while (true) {
        queue<pii> bfsNextSwan;
        queue<pii> bfsNextWater;

        while (!bfsWater.empty()) {
            int y;
            int x;

            tie(y, x) = bfsWater.front();

            a[y][x] = '.';

            bfsWater.pop();

            REP(i, 4) {
                int ny = y + "1201"[i] - '1';
                int nx = x + "0112"[i] - '1';

                if (ny < 0 || ny >= r || nx < 0 || nx >= c || vWater[ny][nx]) continue;

                if (a[ny][nx] == '.') {
                    vWater[ny][nx] = true;

                    bfsWater.emplace(ny, nx);
                } else if (a[ny][nx] == 'X') {
                    vWater[ny][nx] = true;

                    bfsNextWater.emplace(ny, nx);
                }
            }
        }

        while (!bfsSwan.empty()) {
            int y;
            int x;

            tie(y, x) = bfsSwan.front();

            bfsSwan.pop();

            REP(i, 4) {
                int ny = y + "1201"[i] - '1';
                int nx = x + "0112"[i] - '1';

                if (ny < 0 || ny >= r || nx < 0 || nx >= c || vSwan[ny][nx]) continue;

                if (a[ny][nx] == '.') {
                    vSwan[ny][nx] = true;

                    bfsSwan.emplace(ny, nx);
                } else if (a[ny][nx] == 'X') {
                    vSwan[ny][nx] = true;

                    bfsNextSwan.emplace(ny, nx);
                }
            }
        }

        if (vSwan[y2][x2]) {
            PRINTLN(d);

            return 0;
        }

        bfsWater = bfsNextWater;
        bfsSwan = bfsNextSwan;

        d++;
    }
}
