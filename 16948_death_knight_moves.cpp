#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_SIZE 200

int movesAt[MAX_SIZE][MAX_SIZE];

int main() {
    int n;
    int y1;
    int x1;
    int y2;
    int x2;
    queue<pair<int, int>> bfsPoints;

    cin >> n >> y1 >> x1 >> y2 >> x2;

    movesAt[y1][x1] = 1;

    bfsPoints.push({y1, x1});

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop();

        for (int i = 0; i < 6; i++) {
            int ny = y + "002244"[i] - '2';
            int nx = x + "130413"[i] - '2';

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || movesAt[ny][nx]) continue;

            movesAt[ny][nx] = movesAt[y][x] + 1;

            bfsPoints.push({ny, nx});
        }
    }

    cout << (movesAt[y2][x2] ? movesAt[y2][x2] - 1 : -1) << '\n';

    return 0;
}
