#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int stickers[100000][2];
int dp[100000][2];

int memoize(int row, int column) {
    if (row == 0) return stickers[0][column];

    if (row == 1) return stickers[0][(column + 1) % 2] + stickers[1][column];

    int &ret = dp[row][column];

    if (ret != UNKNOWN) return ret;

    return ret = stickers[row][column]
                 + max({memoize(row - 1, (column + 1) % 2),
                        memoize(row - 2, column),
                        memoize(row - 2, (column + 1) % 2)});
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int numRow;

        cin >> numRow;

        for (int i = 0; i < numRow; i++) {
            cin >> stickers[i][0];
        }

        for (int i = 0; i < numRow; i++) {
            cin >> stickers[i][1];
        }

        memset(dp, UNKNOWN, sizeof(dp));

        cout << max(memoize(numRow - 1, 0), memoize(numRow - 1, 1)) << '\n';
    }

    return 0;
}
