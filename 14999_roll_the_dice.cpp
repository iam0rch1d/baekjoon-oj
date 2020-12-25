#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int map[20][20];

int roll(vi &indices, int query) {
    vi temp(indices);

    if (query == 1) indices = {0, temp[4], temp[2], temp[1], temp[6], temp[5], temp[3]};
    else if (query == 2) indices = {0, temp[3], temp[2], temp[6], temp[1], temp[5], temp[4]};
    else if (query == 3) indices = {0, temp[5], temp[1], temp[3], temp[4], temp[6], temp[2]};
    else if (query == 4) indices = {0, temp[2], temp[6], temp[3], temp[4], temp[1], temp[5]};

    return indices[6];
}

int main() {
    int n;
    int m;
    int y;
    int x;
    int k;

    cin >> n >> m >> y >> x >> k;

    FOR(i, 0, n) FOR(j, 0, m) cin >> map[i][j];

    vi indices{0, 1, 2, 3, 4, 5, 6};
    vi dice(7, 0);
    int currentBottomIndex;

    while (k--) {
        int query;

        cin >> query;

        int ny = y + "01102"[query] - '1';
        int nx = x + "02011"[query] - '1';

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        y = ny;
        x = nx;
        currentBottomIndex = roll(indices, query);

        if (!map[y][x]) map[y][x] = dice[currentBottomIndex];
        else {
            dice[currentBottomIndex] = map[y][x];
            map[y][x] = 0;
        }

        PRINTLN(dice[7 - currentBottomIndex]);
    }

    return 0;
}
