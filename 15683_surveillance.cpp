#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int n;
int m;
unsigned camCount;

void behold(vector<vector<int>> &map, pair<int, int> camPoint, unsigned direction) {
    int y;
    int x;
    int distance = 1;

    tie(y, x) = camPoint;

    while (true) {
        int ny = y + ("0121"[direction] - '1') * distance;
        int nx = x + ("1210"[direction] - '1') * distance;

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 6) return;

        if (map[ny][nx] == 0) map[ny][nx] = 7;

        distance++;
    }
}

int countBlindspot(vector<vector<int>> map, vector<pair<int, int>> &camPoints, vector<unsigned> &camDirections) {
    int blindspotCount = 0;

    for (int i = 0; i < camCount; i++) {
        int cy;
        int cx;

        tie(cy, cx) = camPoints[i];

        behold(map, {cy, cx}, camDirections[i]);

        if (map[cy][cx] % 2 == 0 || map[cy][cx] == 5) behold(map, {cy, cx}, (camDirections[i] + 2) % 4);

        if (map[cy][cx] >= 3) behold(map, {cy, cx}, (camDirections[i] + 1) % 4);

        if (map[cy][cx] == 5) behold(map, {cy, cx}, (camDirections[i] + 3) % 4);
    }

    for (auto &mapRow : map) {
        for (int mapElement : mapRow) {
            blindspotCount += !mapElement;
        }
    }

    return blindspotCount;
}

int main() {
    vector<pair<int, int>> camPosistions;
    int minBlindspotCount = 65;

    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] >= 1 && map[i][j] <= 5) {
                camPosistions.emplace_back(i, j);

                camCount++;
            }
        }
    }

    for (unsigned camDirectionBitset = 0; camDirectionBitset < (1u << (camCount << 1u)); camDirectionBitset++) {
        unsigned currentBitset = camDirectionBitset;
        vector<unsigned> camDirections(camCount);

        for (int i = 0; i < camCount; i++) {
            camDirections[i] = currentBitset & 3u;
            currentBitset >>= 2u;
        }

        minBlindspotCount = min(minBlindspotCount, countBlindspot(map, camPosistions, camDirections));
    }

    cout << minBlindspotCount << '\n';

    return 0;
}
