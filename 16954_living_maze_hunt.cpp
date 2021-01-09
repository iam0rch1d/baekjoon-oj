#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

bool isVisited[9][8][8];

int main() {
    string map[8];
    queue<tuple<int, int, int>> bfsPoints;

    for (auto &mapRow : map) {
        cin >> mapRow;
    }

    isVisited[0][7][0] = true;

    bfsPoints.emplace(0, 7, 0);

    while (!bfsPoints.empty()) {
        int time;
        int y;
        int x;

        tie(time, y, x) = bfsPoints.front();

        if (y == 0 && x == 7) {
            cout << "1\n";

            return 0;
        }

        bfsPoints.pop();

        for (int i = 0; i < 9; i++) {
            int nextTime = min(time + 1, 8);
            int ny = y + "000111222"[i] - '1';
            int nx = x + "012012012"[i] - '1';

            if (ny < 0 || ny >= 8 || nx < 0 || nx >= 8
                || (ny - time >= 0 && map[ny - time][nx] == '#')
                || (ny - nextTime >= 0 && map[ny - nextTime][nx] == '#')
                || isVisited[nextTime][ny][nx]) {
                continue;
            }

            isVisited[nextTime][ny][nx] = true;

            bfsPoints.emplace(nextTime, ny, nx);
        }
    }

    cout << "0\n";

    return 0;
}
