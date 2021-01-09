#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int mirrorsAt[100][100];

int main() {
    int h;
    int w;
    int cy = -1;
    int cx;
    queue<pair<int, int>> bfsLaserPoints;

    cin >> w >> h;

    vector<string> map(h);

    for (int i = 0; i < h; i++) {
        cin >> map[i];

        for (int j = 0; j < w; j++) {
            if (map[i][j] == 'C' && cy == -1) {
                tie(cy, cx) = {i, j};

                mirrorsAt[cy][cx] = 1;

                bfsLaserPoints.emplace(cy, cx);
            }
        }
    }

    while (!bfsLaserPoints.empty()) {
        int y;
        int x;

        tie(y, x) = bfsLaserPoints.front();

        if (map[y][x] == 'C' && mirrorsAt[y][x] != 1) {
            cout << mirrorsAt[y][x] - 2 << '\n';

            return 0;
        }

        bfsLaserPoints.pop();

        for (int i = 0; i < 4; i++) {
            int distance = 1;

            while (true) {
                int ny = y + distance * ("1201"[i] - '1');
                int nx = x + distance * ("0112"[i] - '1');

                if (ny < 0 || ny >= h || nx < 0 || nx >= w || map[ny][nx] == '*') break;

                if (!mirrorsAt[ny][nx]) {
                    mirrorsAt[ny][nx] = mirrorsAt[y][x] + 1;

                    bfsLaserPoints.emplace(ny, nx);
                }

                distance++;
            }
        }
    }
}
