#include <algorithm>
#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int stickers[100000][2];
int maxTotalScoreCache[100000][2];

int memoizeTotalScore(int row, int column) {
    if (row == 0) return stickers[0][column];

    if (row == 1) return stickers[0][(column + 1) % 2] + stickers[1][column];

    int &totalScore = maxTotalScoreCache[row][column];

    if (totalScore != UNMEMOIZED) return totalScore;

    return totalScore = stickers[row][column]
                        + max({memoizeTotalScore(row - 1, (column + 1) % 2),
                               memoizeTotalScore(row - 2, column),
                               memoizeTotalScore(row - 2, (column + 1) % 2)});
}

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int numRow;

        cin >> numRow;

        for (int i = 0; i < numRow; i++) {
            cin >> stickers[i][0];
        }

        for (int i = 0; i < numRow; i++) {
            cin >> stickers[i][1];
        }

        memset(maxTotalScoreCache, UNMEMOIZED, sizeof(maxTotalScoreCache));

        cout << max(memoizeTotalScore(numRow - 1, 0), memoizeTotalScore(numRow - 1, 1)) << '\n';
    }

    return 0;
}
