#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n;

int bfsPrey(vector<vector<int>> &map, int &sy, int &sx, int size) {
    vector<vector<int>> distanceTo(n, vector<int>(n, -1));
    queue<pair<int, int>> bfsDistanceQueue;
    vector<tuple<int, int, int>> preys;
    int preyDistance;
    int py;
    int px;

    distanceTo[sy][sx] = 0;

    bfsDistanceQueue.push({sy, sx});

    while (!bfsDistanceQueue.empty()) {
        int y;
        int x;

        tie(y, x) = bfsDistanceQueue.front();

        bfsDistanceQueue.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || distanceTo[ny][nx] != -1 || size < map[ny][nx]) continue;

            distanceTo[ny][nx] = distanceTo[y][x] + 1;

            if (map[ny][nx] && size > map[ny][nx]) preys.emplace_back(distanceTo[ny][nx], ny, nx);

            bfsDistanceQueue.push({ny, nx});
        }
    }

    if (preys.empty()) return 0;

    sort(preys.begin(), preys.end());

    tie(preyDistance, py, px) = preys[0];

    map[py][px] = 0;
    sy = py;
    sx = px;

    return preyDistance;
}

int main() {
    int sy;
    int sx;
    int size = 2;
    int bfsCount = 0;
    int totalDistance = 0;

    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 9) {
                sy = i;
                sx = j;
                map[i][j] = 0;
            }
        }
    }

    while (true) {
        int preyDistance = bfsPrey(map, sy, sx, size);

        if (preyDistance) {
            bfsCount++;
            totalDistance += preyDistance;
        } else break;

        if (bfsCount == size) {
            size++;
            bfsCount = 0;
        }
    }

    cout << totalDistance << '\n';

    return 0;
}
