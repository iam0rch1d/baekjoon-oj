#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
void chmin(T &m, T q) { m = min(m, q); }

int scv[3];
int dp[61][61][61];

int memoize(int x, int y, int z) {
    x = max(x, 0);
    y = max(y, 0);
    z = max(z, 0);

    if (!x && !y && !z) return 0;

    int &ret = dp[x][y][z];

    if (ret != -1) return ret;

    ret = 987654321;

    for (int i = 0; i < 6; i++) {
        int nx = x - "113399"[i] + '0';
        int ny = y - "391913"[i] + '0';
        int nz = z - "939131"[i] + '0';

        chmin(ret, memoize(nx, ny, nz) + 1);
    }

    return ret;
}

int main() {
    int n;

    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }

    cout << memoize(scv[0], scv[1], scv[2]) << '\n';

    return 0;
}
