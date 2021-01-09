#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

using pbb = pair<bool, bool>;
using vi = vector<int>;
using vstr = vector<string>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int n;
int m;

// (<is moved>, <is in hole>)
pbb roll(vstr &a, int &y, int &x, unsigned direction) {
    if (a[y][x] == '.') return {false, true};

    bool retF = false;

    while (true) {
        int ny = y + "0121"[direction] - '1';
        int nx = x + "1210"[direction] - '1';

        if (a[ny][nx] == '#' || a[ny][nx] == 'R' || a[ny][nx] == 'B') return {retF, false};
        else if (a[ny][nx] == '.') {
            swap(a[y][x], a[ny][nx]);
            tie(y, x) = {ny, nx};
            retF = true;
        } else if (a[ny][nx] == 'O') {
            a[y][x] = '.';

            return {true, true};
        }
    }
}

int tilt(vstr a, vi &directions) {
    int ry;
    int rx;
    int by;
    int bx;
    int ret = 0;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (a[i][j] == 'R') tie(ry, rx) = {i, j};
            else if (a[i][j] == 'B') tie(by, bx) = {i, j};
        }
    }

    for (unsigned direction : directions) {
        bool isRedInHole = false;
        bool isBlueInHole = false;

        ret++;

        while (true) {
            pbb redStates = roll(a, ry, rx, direction);
            pbb blueStates = roll(a, by, bx, direction);

            if (!redStates.F && !blueStates.F) break;

            if (redStates.S) isRedInHole = true;

            if (blueStates.S) isBlueInHole = true;
        }

        if (isBlueInHole) return 11;

        if (isRedInHole) return ret;
    }

    return 11;
}

int main() {
    int ans = 11;
    int ansBitset = 1 << 20;

    cin >> n >> m;

    vstr a(n);

    for (string &ai : a) {
        cin >> ai;
    }

    REP(tiltBitset, 1 << 20) {
        int currentBitset = tiltBitset;
        vi directions(10, 4);
        bool isValid = true;

        for (int i = 0; i < 10; i++) {
            directions[i] = currentBitset & 3;

            if (i != 0 && !((directions[i] & 1) ^ (directions[i - 1] & 1))) {
                isValid = false;

                break;
            }

            currentBitset >>= 2;
        }

        if (isValid) {
            int currentTiltCount = tilt(a, directions);

            if (ans > currentTiltCount) {
                ans = currentTiltCount;
                ansBitset = tiltBitset;
            }
        }
    }

    PRINTLN(ans == 11 ? -1 : ans);

    REP(i, ans == 11 ? 0 : ans) {
        unsigned direction = ansBitset & 3;

        cout << "URDL"[direction];

        ansBitset >>= 2;
    }

    PRINTLN("");

    return 0;
}
