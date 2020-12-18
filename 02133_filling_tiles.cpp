#include <cstring>
#include <iostream>

using namespace std;

int dp[16];

int memoize(int width) {
    if (width == 0) return 1;

    int &tilingCount = dp[width / 2];

    if (tilingCount != -1) return tilingCount;

    tilingCount = 3 * memoize(width - 2);

    for (int i = width - 4; i >= 0; i -= 2) {
        tilingCount += 2 * memoize(i);
    }

    return tilingCount;
}

int main() {
    int width;

    memset(dp, -1, sizeof(dp));

    cin >> width;

    if (width % 2 != 0) {
        cout << "0\n";

        return 0;
    }

    cout << memoize(width) << '\n';

    return 0;
}
