#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n;
int areaNoAt[100][100];

void bfsArea(vector<string> &map, int sy, int sx, int areaNo) {
    queue<pair<int, int>> bfsPoints;

    areaNoAt[sy][sx] = areaNo;

    bfsPoints.emplace(sy, sx);

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || areaNoAt[ny][nx] || map[ny][nx] != map[y][x]) continue;

            areaNoAt[ny][nx] = areaNo;

            bfsPoints.emplace(ny, nx);
        }
    }
}

int main() {
    int areaNo = 0;

    cin >> n;

    vector<string> map(n);

    for (auto &mapRow : map) {
        cin >> mapRow;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!areaNoAt[i][j]) bfsArea(map, i, j, ++areaNo);
        }
    }

    cout << areaNo << ' ';

    memset(areaNoAt, 0, sizeof(areaNoAt));

    areaNo = 0;

    for (auto &mapRow : map) {
        for (int i = 0; i < n; i++) {
            if (mapRow[i] == 'G') mapRow[i] = 'R';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!areaNoAt[i][j]) bfsArea(map, i, j, ++areaNo);
        }
    }

    cout << areaNo << '\n';

    return 0;
}
