#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

#define MAX_SIZE 100

int n;
int m;
bool map[MAX_SIZE][MAX_SIZE];
bool isVisited[MAX_SIZE][MAX_SIZE];

int bfsArea(int sy, int sx) {
    int areaSurface = 0;
    queue<pair<int, int>> bfsPoints;

    isVisited[sy][sx] = true;

    bfsPoints.emplace(sy, sx);

    while (!bfsPoints.empty()) {
        int y;
        int x;

        areaSurface++;
        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] || isVisited[ny][nx]) continue;

            isVisited[ny][nx] = true;

            bfsPoints.emplace(ny, nx);
        }
    }

    return areaSurface;
}

int main() {
    int k;
    vector<int> areaSurfaces;

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x1;
        int y1;
        int x2;
        int y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                map[y][x] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j] && !isVisited[i][j]) areaSurfaces.push_back(bfsArea(i, j));
        }
    }

    sort(areaSurfaces.begin(), areaSurfaces.end());

    cout << areaSurfaces.size() << '\n';

    for (int areaSurface : areaSurfaces) {
        cout << areaSurface << ' ';
    }

    cout << '\n';

    return 0;
}
