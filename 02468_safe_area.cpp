#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;
int map[100][100];
int safeAreaNoAt[100][100];

void bfsSafeArea(int sy, int sx, int threshold, int safeAreaNo) {
    queue<pair<int, int>> bfsPoints;

    safeAreaNoAt[sy][sx] = safeAreaNo;

    bfsPoints.emplace(sy, sx);

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || safeAreaNoAt[ny][nx] || map[ny][nx] < threshold) continue;

            safeAreaNoAt[ny][nx] = safeAreaNo;

            bfsPoints.emplace(ny, nx);
        }
    }
}

int main() {
    int maxSafeAreaCount = 0;
    int minThreshold = 101;
    int maxThreshold = 1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            minThreshold = min(minThreshold, map[i][j]);
            maxThreshold = max(maxThreshold, map[i][j]);
        }
    }

    for (int threshold = minThreshold; threshold <= maxThreshold; threshold++) {
        int safeAreaNo = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!safeAreaNoAt[i][j] && map[i][j] >= threshold) bfsSafeArea(i, j, threshold, ++safeAreaNo);
            }
        }

        maxSafeAreaCount = max(maxSafeAreaCount, safeAreaNo);

        memset(safeAreaNoAt, 0, sizeof(safeAreaNoAt));
    }

    cout << maxSafeAreaCount << '\n';

    return 0;
}
