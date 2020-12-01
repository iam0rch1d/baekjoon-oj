#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n;
int m;

int bfsSafeArea(vector<vector<int>> map) {
    queue<pair<int, int>> bfsPoints;
    int safeArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) bfsPoints.push({i, j});
        }
    }

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx]) continue;

            map[ny][nx] = 2;

            bfsPoints.push({ny, nx});
        }
    }

    for (auto &mapRow : map) {
        for (int mapElement : mapRow) {
            safeArea += mapElement == 0;
        }
    }

    return safeArea;
}

int main() {
    int numElement;
    int maxSafeArea = 0;

    cin >> n >> m;

    numElement = n * m;

    vector<vector<int>> map(n, vector<int>(m));

    for (auto &mapRow : map) {
        for (int &mapElement : mapRow) {
            cin >> mapElement;
        }
    }

    for (int i = 0; i < numElement - 2; i++) {
        int iy = i / m;
        int ix = i % m;

        if (map[iy][ix]) continue;

        map[iy][ix] = 1;

        for (int j = i + 1; j < numElement - 1; j++) {
            int jy = j / m;
            int jx = j % m;

            if (map[jy][jx]) continue;

            map[jy][jx] = 1;

            for (int k = j + 1; k < numElement; k++) {
                int ky = k / m;
                int kx = k % m;

                if (map[ky][kx]) continue;

                map[ky][kx] = 1;

                maxSafeArea = max(maxSafeArea, bfsSafeArea(map));

                map[ky][kx] = 0;
            }

            map[jy][jx] = 0;
        }

        map[iy][ix] = 0;
    }

    cout << maxSafeArea << '\n';

    return 0;
}
