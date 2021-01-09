#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;
int m;
int map[20][20];
bool isVisited[20][20];

int bfsKillArea(int sy, int sx) {
    queue<pair<int, int>> bfsPoints;
    bool canKill = true;
    int killArea = 0;

    isVisited[sy][sx] = true;

    bfsPoints.emplace(sy, sx);

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        if (!map[y][x]) canKill = false;

        killArea++;

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 1 || isVisited[ny][nx]) continue;

            isVisited[ny][nx] = true;

            bfsPoints.emplace(ny, nx);
        }
    }

    return canKill ? killArea : 0;
}

int main() {
    int nm;
    int maxKillArea = 0;

    cin >> n >> m;

    nm = n * m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int point1 = 0; point1 < nm; point1++) {
        int y1 = point1 / m;
        int x1 = point1 % m;

        if (map[y1][x1]) continue;

        map[y1][x1] = 1;

        for (int point2 = point1 + 1; point2 < nm; point2++) {
            int y2 = point2 / m;
            int x2 = point2 % m;

            if (map[y2][x2]) continue;

            int killArea = 0;

            map[y2][x2] = 1;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] != 1 && !isVisited[i][j]) killArea += bfsKillArea(i, j);
                }
            }

            map[y2][x2] = 0;
            maxKillArea = max(maxKillArea, killArea);

            memset(isVisited, false, sizeof(isVisited));
        }

        map[y1][x1] = 0;
    }

    cout << maxKillArea << '\n';

    return 0;
}
