#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vvvpii = vector<vvpii>;
using vvvvpii = vector<vvvpii>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

template<typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.F + r.F, l.S + r.S}; }

#define INF 987654321

int a[10][10];
int dy[3][8] = {{-2, -2, -1, -1, 1, 1, 2, 2},
                {-1, -1, 1,  1},
                {-1, 0,  0,  1}};
int dx[3][8] = {{-1, 1,  -2, 2, -2, 2, -1, 1},
                {-1, 1,  -1, 1},
                {0,  -1, 1,  0}};

int main() {
    int n;

    cin >> n;

    vvvvpii dist(n, vvvpii(n, vvpii(n * n, vpii(3, {INF, INF}))));
    queue<tuple<int, int, int, int>> bfsVertices;  // (<y>, <x>, <number>, <piece>)

    REP(i, n) {
        REP(j, n) {
            cin >> a[i][j];

            if (--a[i][j] == 0) {
                REP(k, 3) {
                    dist[i][j][0][k] = {0, 0};

                    bfsVertices.push({i, j, 0, k});
                }
            }
        }
    }

    pii ans{INF, INF};

    while (!bfsVertices.empty()) {
        int y;
        int x;
        int number;
        int piece;

        tie(y, x, number, piece) = bfsVertices.front();

        auto &state = dist[y][x][number][piece];

        if (number == n * n - 1) chmin(ans, state);

        bfsVertices.pop();

        // Move
        REP(i, piece == 0 ? 8 : 4) {
            int d = 1;

            while (true) {
                int ny = y + d * dy[piece][i];
                int nx = x + d * dx[piece][i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;

                int nextNumber = number + (a[ny][nx] == number + 1);
                auto &nextState = dist[ny][nx][nextNumber][piece];

                if (chmin(nextState, state + make_pair(1, 0))) bfsVertices.push({ny, nx, nextNumber, piece});

                if (piece == 0) break;

                d++;
            }
        }

        // Change piece
        REP(i, 3) {
            if (i == piece) continue;

            if (chmin(dist[y][x][number][i], state + make_pair(1, 1))) bfsVertices.push({y, x, number, i});
        }
    }

    PRINT(ans.F);
    PRINTLN(ans.S);

    return 0;
}
