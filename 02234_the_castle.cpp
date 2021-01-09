#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n;
int m;
int wallMap[50][50];
int roomNoAt[50][50];
vector<int> roomAreas;

void bfsRoomNo(int sy, int sx, int roomNo) {
    queue<pair<int, int>> bfsPoints;
    int roomArea = 1;

    roomNoAt[sy][sx] = roomNo;

    bfsPoints.emplace(sy, sx);

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (unsigned i = 0; i < 4; i++) {
            int ny = y + "1012"[i] - '1';
            int nx = x + "0121"[i] - '1';

            if ((wallMap[y][x] & (1u << i)) || ny < 0 || ny >= n || nx < 0 || nx >= m || roomNoAt[ny][nx]) continue;

            roomNoAt[ny][nx] = roomNo;
            roomArea++;

            bfsPoints.emplace(ny, nx);
        }
    }

    roomAreas.push_back(roomArea);
}

int main() {
    int roomCount = 0;
    int maxMergedRoomArea = 0;

    cin >> m >> n;

    roomAreas.push_back(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> wallMap[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!roomNoAt[i][j]) bfsRoomNo(i, j, ++roomCount);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                int ni = i + "10"[k] - '0';
                int nj = j + "01"[k] - '0';

                if (ni >= n || nj >= m || roomNoAt[i][j] == roomNoAt[ni][nj]) continue;

                maxMergedRoomArea = max(maxMergedRoomArea, roomAreas[roomNoAt[i][j]] + roomAreas[roomNoAt[ni][nj]]);
            }
        }
    }

    cout << roomCount << '\n' << *max_element(roomAreas.begin(), roomAreas.end()) << '\n' << maxMergedRoomArea << '\n';

    return 0;
}
