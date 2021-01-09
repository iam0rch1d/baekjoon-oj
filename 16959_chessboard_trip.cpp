#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;

#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

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

    vvvvi dist(n, vvvi(n, vvi(n * n, vi(3, INF))));
    queue<tuple<int, int, int, int>> bfsVertices;  // (<y>, <x>, <number>, <piece>)

    REP(i, n) {
        REP(j, n) {
            cin >> a[i][j];

            if (--a[i][j] == 0) {
                REP(k, 3) {
                    dist[i][j][0][k] = 0;

                    bfsVertices.emplace(i, j, 0, k);
                }
            }
        }
    }

    while (!bfsVertices.empty()) {
        int y;
        int x;
        int number;
        int piece;

        tie(y, x, number, piece) = bfsVertices.front();

        int &state = dist[y][x][number][piece];

        if (number == n * n - 1) {
            PRINTLN(state);

            return 0;
        }

        bfsVertices.pop();

        // Move
        REP(i, piece == 0 ? 8 : 4) {
            int d = 1;

            while (true) {
                int ny = y + d * dy[piece][i];
                int nx = x + d * dx[piece][i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;

                int nextNumber = number + (a[ny][nx] == number + 1);
                int &nextState = dist[ny][nx][nextNumber][piece];

                if (chmin(nextState, state + 1)) bfsVertices.emplace(ny, nx, nextNumber, piece);

                if (piece == 0) break;

                d++;
            }
        }

        // Change piece
        REP(i, 3) {
            if (i == piece) continue;

            if (chmin(dist[y][x][number][i], dist[y][x][number][piece] + 1)) bfsVertices.emplace(y, x, number, i);
        }
    }
}
