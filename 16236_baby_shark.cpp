#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n;

int bfsPrey(vector<vector<int>> &a, int &sy, int &sx, int level) {
    vector<vector<int>> distanceTo(n, vector<int>(n, -1));
    queue<pair<int, int>> bfsDistanceQueue;
    vector<tuple<int, int, int>> preys;
    int preyDistance;

    distanceTo[sy][sx] = 0;

    bfsDistanceQueue.emplace(sy, sx);

    while (!bfsDistanceQueue.empty()) {
        int y;
        int x;

        tie(y, x) = bfsDistanceQueue.front();

        bfsDistanceQueue.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || distanceTo[ny][nx] != -1 || level < a[ny][nx]) continue;

            distanceTo[ny][nx] = distanceTo[y][x] + 1;

            if (a[ny][nx] && level > a[ny][nx]) preys.emplace_back(distanceTo[ny][nx], ny, nx);

            bfsDistanceQueue.emplace(ny, nx);
        }
    }

    if (preys.empty()) return 0;

    sort(preys.begin(), preys.end());

    tie(preyDistance, sy, sx) = preys[0];
    a[sy][sx] = 0;

    return preyDistance;
}

int main() {
    int sy;
    int sx;
    int level = 2;
    int experience = 0;
    int totalDistance = 0;

    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];

            if (a[i][j] == 9) {
                tie(sy, sx) = {i, j};
                a[i][j] = 0;
            }
        }
    }

    while (true) {
        int preyDistance = bfsPrey(a, sy, sx, level);

        if (preyDistance) {
            experience++;
            totalDistance += preyDistance;
        } else break;

        if (experience == level) {
            level++;
            experience = 0;
        }
    }

    cout << totalDistance << '\n';

    return 0;
}
