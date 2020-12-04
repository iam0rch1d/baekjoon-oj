#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int map[50][50];

int main() {
    int n;
    int m;
    queue<pair<int, int>> bfsPoints;
    int maxSafeDistance = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j]) bfsPoints.push({i, j});
        }
    }

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 8; i++) {
            int ny = y + "00011222"[i] - '1';
            int nx = x + "01202012"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx]) continue;

            map[ny][nx] = map[y][x] + 1;
            maxSafeDistance = max(maxSafeDistance, map[ny][nx] - 1);

            bfsPoints.push({ny, nx});
        }
    }

    cout << maxSafeDistance << '\n';

    return 0;
}
