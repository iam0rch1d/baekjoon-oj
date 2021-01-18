#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

int dp[100][2][101];

int main() {
    string scroll;
    string a[2];

    cin >> scroll >> a[0] >> a[1];

    a[0] = '.' + a[0];
    a[1] = '.' + a[1];

    int scrollSize = scroll.size();
    int columnSize = a[0].size();

    FUN<int(int, int, int)> memoize = [&](int index, int y, int x) {
        if (index == scrollSize) return 1;

        int &ret = dp[index][y][x];

        if (ret != -1) return ret;

        ret = 0;

        FOR(i, x + 1, columnSize) if (a[1 - y][i] == scroll[index]) ret += memoize(index + 1, 1 - y, i);

        return ret;
    };

    RESET(dp, -1);
    PRINTLN(memoize(0, 0, 0) + memoize(0, 1, 0));

    return 0;
}
