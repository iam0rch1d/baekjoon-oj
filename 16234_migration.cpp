#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;
int l;
int r;
int a[50][50];
int frontierNoAt[50][50];
int frontierPopulations[2501];
int frontierSizes[2501];

void bfsFrontierNo(int sy, int sx, int frontierNo) {
    queue<pair<int, int>> bfsPoints;

    frontierPopulations[frontierNo] = a[sy][sx];
    frontierSizes[frontierNo] = 1;
    frontierNoAt[sy][sx] = frontierNo;

    bfsPoints.emplace(sy, sx);

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || frontierNoAt[ny][nx]) continue;

            int difference = abs(a[ny][nx] - a[y][x]);

            if (difference >= l && difference <= r) {
                frontierNoAt[ny][nx] = frontierNo;
                frontierPopulations[frontierNo] += a[ny][nx];
                frontierSizes[frontierNo]++;

                bfsPoints.emplace(ny, nx);
            }
        }
    }
}

int main() {
    int migrations = 0;

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        int frontierCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!frontierNoAt[i][j]) bfsFrontierNo(i, j, ++frontierCount);
            }
        }

        if (frontierCount == n * n) break;

        migrations++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = frontierPopulations[frontierNoAt[i][j]] / frontierSizes[frontierNoAt[i][j]];
            }
        }

        memset(frontierNoAt, 0, sizeof(frontierNoAt));
        memset(frontierPopulations, 0, sizeof(frontierPopulations));
        memset(frontierSizes, 0, sizeof(frontierSizes));
    }

    cout << migrations << '\n';

    return 0;
}
