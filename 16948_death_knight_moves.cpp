#include <cstring>
#include <iostream>
#include <queue>

#define MAX_SIZE 200

using namespace std;

int moveCountAt[MAX_SIZE][MAX_SIZE];

int main() {
    int n;
    int y1;
    int x1;
    int y2;
    int x2;
    queue<pair<int, int>> bfsPoints;

    cin >> n >> y1 >> x1 >> y2 >> x2;

    moveCountAt[y1][x1] = 1;

    bfsPoints.push({y1, x1});

    while (!bfsPoints.empty()) {
        pair<int, int> current = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 6; i++) {
            int ny = current.first + "002244"[i] - '2';
            int nx = current.second + "130413"[i] - '2';

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || moveCountAt[ny][nx]) continue;

            moveCountAt[ny][nx] = moveCountAt[current.first][current.second] + 1;

            bfsPoints.push({ny, nx});
        }
    }

    cout << (moveCountAt[y2][x2] ? moveCountAt[y2][x2] - 1 : -1) << '\n';

    return 0;
}
