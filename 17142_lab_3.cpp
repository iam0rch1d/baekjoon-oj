#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

#define INF_TIME 2501

int main() {
    int n;
    unsigned m;
    vector<pair<int, int>> virusPoints;
    int virusPointCount = 0;
    int minTotalInfectionTime = INF_TIME;

    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2) {
                virusPoints.emplace_back(i, j);

                virusPointCount++;
            }
        }
    }

    for (unsigned virusBitset = 1u; virusBitset < (1u << virusPointCount); virusBitset++) {
        if (__builtin_popcount(virusBitset) > m) continue;

        vector<vector<int>> infectionTimeAt(n, vector<int>(n, -1));
        queue<pair<int, int>> bfsPoints;
        int totalInfectionTime = 0;

        for (unsigned i = 0; i < virusPointCount; i++) {
            map[virusPoints[i].first][virusPoints[i].second] = (virusBitset & (1u << i)) ? 3 : 2;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 3) {
                    infectionTimeAt[i][j] = 0;

                    bfsPoints.emplace(i, j);
                }
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

                if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == 1 || infectionTimeAt[ny][nx] != -1) {
                    continue;
                }

                infectionTimeAt[ny][nx] = infectionTimeAt[y][x] + 1;

                bfsPoints.emplace(ny, nx);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j]) continue;

                if (infectionTimeAt[i][j] == -1) {
                    totalInfectionTime = INF_TIME;

                    break;
                }

                totalInfectionTime = max(totalInfectionTime, infectionTimeAt[i][j]);
            }

            if (totalInfectionTime == INF_TIME) break;
        }

        minTotalInfectionTime = min(minTotalInfectionTime, totalInfectionTime);
    }

    cout << (minTotalInfectionTime == INF_TIME ? -1 : minTotalInfectionTime) << '\n';

    return 0;
}
