#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

#define MAX_SIZE 1000

using namespace std;

int n;
int m;
int map[MAX_SIZE][MAX_SIZE];
int spaceNoAt[MAX_SIZE][MAX_SIZE];
vector<int> spaceAreas;

void bfsSpaceNo(int sy, int sx, int spaceNo) {
    queue<pair<int, int>> bfsPoints;
    int spaceArea = 1;

    spaceNoAt[sy][sx] = spaceNo;

    bfsPoints.push({sy, sx});

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] || spaceNoAt[ny][nx]) continue;

            spaceNoAt[ny][nx] = spaceNo;
            spaceArea++;

            bfsPoints.push({ny, nx});
        }
    }

    spaceAreas.push_back(spaceArea);
}

int main() {
    int spaceNo = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string mapRow;

        cin >> mapRow;

        for (int j = 0; j < m; j++) {
            map[i][j] = mapRow[j] - '0';
        }
    }

    spaceAreas.push_back(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!map[i][j] && !spaceNoAt[i][j]) bfsSpaceNo(i, j, ++spaceNo);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) {
                set<int> adjacentSpaces;

                for (int k = 0; k < 4; k++) {
                    int ni = i + "1201"[k] - '1';
                    int nj = j + "0112"[k] - '1';

                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj]) continue;

                    adjacentSpaces.insert(spaceNoAt[ni][nj]);
                }

                for (int adjacentSpaceNo : adjacentSpaces) {
                    map[i][j] += spaceAreas[adjacentSpaceNo];
                }
            }

            cout << map[i][j] % 10;
        }

        cout << '\n';
    }

    return 0;
}
