#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

template<typename T>
void chmin(T &m, T q) {
    m = min(m, q);
}

int scv[3];
int attackCountCache[61][61][61];

int memoizeAttackCount(int x, int y, int z) {
    x = max(x, 0);
    y = max(y, 0);
    z = max(z, 0);

    if (!x && !y && !z) return 0;

    int &attackCount = attackCountCache[x][y][z];

    if (attackCount != UNKNOWN) return attackCount;

    attackCount = 987654321;

    for (int i = 0; i < 6; i++) {
        int nx = x - "113399"[i] + '0';
        int ny = y - "391913"[i] + '0';
        int nz = z - "939131"[i] + '0';

        chmin(attackCount, memoizeAttackCount(nx, ny, nz) + 1);
    }

    return attackCount;
}

int main() {
    int n;

    memset(attackCountCache, UNKNOWN, sizeof(attackCountCache));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }

    cout << memoizeAttackCount(scv[0], scv[1], scv[2]) << '\n';

    return 0;
}
