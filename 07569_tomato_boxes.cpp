#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_SIZE 100

int map[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int main() {
    int h;
    int n;
    int m;
    queue<tuple<int, int, int>> bfsPoints;
    int maxDays = 0;

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[i][j][k];

                if (map[i][j][k] == 1) bfsPoints.push({i, j, k});
            }
        }
    }

    while (!bfsPoints.empty()) {
        int z;
        int y;
        int x;

        tie(z, y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 6; i++) {
            int nz = z + "011112"[i] - '1';
            int ny = y + "112011"[i] - '1';
            int nx = x + "101121"[i] - '1';

            if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m || map[nz][ny][nx]) continue;

            map[nz][ny][nx] = map[z][y][x] + 1;

            bfsPoints.push({nz, ny, nx});
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (!map[i][j][k]) {
                    cout << "-1\n";

                    return 0;
                }

                maxDays = max(maxDays, map[i][j][k]);
            }
        }
    }

    cout << maxDays - 1 << '\n';

    return 0;
}
