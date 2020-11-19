#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;
int m;
int map[300][300];
int toMeltHeightAt[300][300];
int icebergNoAt[300][300];

void bfsIcebergNo(int sy, int sx, int icebergNo) {
    queue<pair<int, int>> bfsPoints;

    icebergNoAt[sy][sx] = icebergNo;

    bfsPoints.push({sy, sx});

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (!map[ny][nx] || icebergNoAt[ny][nx]) continue;

            icebergNoAt[ny][nx] = icebergNo;

            bfsPoints.push({ny, nx});
        }
    }
}

int main() {
    int icebergCount = 0;
    int days = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (!map[i][j]) continue;

                for (int k = 0; k < 4; k++) {
                    int ni = i + "1201"[k] - '1';
                    int nj = j + "0112"[k] - '1';

                    toMeltHeightAt[i][j] += !map[ni][nj];
                }
            }
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                map[i][j] = max(map[i][j] - toMeltHeightAt[i][j], 0);
            }
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (map[i][j] && !icebergNoAt[i][j]) bfsIcebergNo(i, j, ++icebergCount);
            }
        }

        days++;

        if (icebergCount >= 2) break;
        else if (icebergCount == 0) {
            cout << "0\n";

            return 0;
        }

        memset(toMeltHeightAt, 0, sizeof(toMeltHeightAt));
        memset(icebergNoAt, 0, sizeof(icebergNoAt));

        icebergCount = 0;
    }

    cout << days << '\n';

    return 0;
}
