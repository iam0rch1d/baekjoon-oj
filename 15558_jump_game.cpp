#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

using pii = pair<int, int>;
using vstr = vector<string>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

int dist[2][100000];

int main() {
    int n;
    int k;
    string a[2];

    cin >> n >> k >> a[0] >> a[1];

    RESET(dist, -1);

    dist[0][0] = 0;

    queue<pii> bfsVertices;

    bfsVertices.emplace(0, 0);

    int dy[]{0, 0, 1};
    int dx[]{1, -1, k};
    bool ans = false;

    while (!bfsVertices.empty()) {
        int y;
        int x;

        tie(y, x) = bfsVertices.front();

        bfsVertices.pop();

        REP(i, 3) {
            int ny = (y + dy[i]) % 2;
            int nx = x + dx[i];

            if (nx >= n) {
                ans = true;

                break;
            }

            if (nx < 0 || a[ny][nx] == '0' || dist[ny][nx] != -1 || nx < dist[y][x] + 1) continue;

            dist[ny][nx] = dist[y][x] + 1;

            bfsVertices.emplace(ny, nx);
        }

        if (ans) break;
    }

    PRINTLN(ans);

    return 0;
}
