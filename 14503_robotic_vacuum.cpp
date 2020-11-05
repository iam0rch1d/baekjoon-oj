#include <iostream>

using namespace std;

int map[50][50];
bool isVisited[50][50];

int main() {
    int n;
    int m;
    int r;
    int c;
    int d;
    int cleaningCount = 0;

    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        bool cantMove = true;

        isVisited[r][c] = true;

        for (int i = 3; i >= 0; i--) {
            int nd;
            int nr;
            int nc;

            nd = (d + i) % 4;
            nr = r + "0121"[nd] - '1';
            nc = c + "1210"[nd] - '1';

            if (!map[nr][nc] && !isVisited[nr][nc]) {
                cantMove = false;
                r = nr;
                c = nc;
                d = nd;

                break;
            }
        }

        if (cantMove) {
            int backward = (d + 2) % 4;
            int nr = r + "0121"[backward] - '1';
            int nc = c + "1210"[backward] - '1';

            if (map[nr][nc]) break;

            r = nr;
            c = nc;
        }
    }

    for (int i = 1; i <= n - 2; i++) {
        for (int j = 1; j <= m - 2; j++) {
            cleaningCount += isVisited[i][j];
        }
    }

    cout << cleaningCount << '\n';

    return 0;
}
