#include <iostream>
#include <deque>
#include <tuple>
#include <vector>

using namespace std;

int h;
int w;

vector<vector<int>> bfsDoorOpens(vector<string> &map, int sy, int sx) {
    vector<vector<int>> doorOpensAt(h + 2, vector<int>(w + 2, -1));
    deque<pair<int, int>> bfsPoints;

    doorOpensAt[sy][sx] = 0;

    bfsPoints.push_front({sy, sx});

    while (!bfsPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsPoints.front();

        bfsPoints.pop_front();

        for (int i = 0; i < 4; i++) {
            int ny = y + "1201"[i] - '1';
            int nx = x + "0112"[i] - '1';

            if (ny < 0 || ny >= h + 2 || nx < 0 || nx >= w + 2 || map[ny][nx] == '*' || doorOpensAt[ny][nx] != -1) {
                continue;
            }

            doorOpensAt[ny][nx] = doorOpensAt[y][x] + (map[ny][nx] == '#');

            map[ny][nx] == '#' ? bfsPoints.emplace_back(ny, nx) : bfsPoints.emplace_front(ny, nx);
        }
    }

    return doorOpensAt;
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int y1 = -1;
        int x1;
        int y2;
        int x2;
        int minTotalDoorOpens = 10001;

        cin >> h >> w;

        vector<string> map(h + 2);

        map[0] = string(w + 2, '.');
        map[h + 1] = map[0];

        for (int i = 1; i <= h; i++) {
            cin >> map[i];

            map[i] = '.' + map[i] + '.';

            for (int j = 1; j <= w; j++) {
                if (map[i][j] == '$') (y1 == -1 ? tie(y1, x1) : tie(y2, x2)) = {i, j};
            }
        }

        auto doorOpensAt0 = bfsDoorOpens(map, 0, 0);
        auto doorOpensAt1 = bfsDoorOpens(map, y1, x1);
        auto doorOpensAt2 = bfsDoorOpens(map, y2, x2);

        for (int i = 0; i < h + 2; i++) {
            for (int j = 0; j < w + 2; j++) {
                if (map[i][j] == '*') continue;

                minTotalDoorOpens = min(minTotalDoorOpens, doorOpensAt0[i][j]
                                                           + doorOpensAt1[i][j]
                                                           + doorOpensAt2[i][j]
                                                           - (map[i][j] == '#' ? 2 : 0));
            }
        }

        cout << minTotalDoorOpens << '\n';
    }

    return 0;
}
