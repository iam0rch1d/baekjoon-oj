#include <algorithm>
#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int stickers[100000][2];
int maxTotalScoreCache[100000][2];

int memoizeTotalScore(int currentRow, int currentColumn) {
    if (currentRow == 0) return stickers[0][currentColumn];

    if (currentRow == 1) return stickers[0][(currentColumn + 1) % 2] + stickers[1][currentColumn];

    int &totalScore = maxTotalScoreCache[currentRow][currentColumn];

    if (totalScore != UNMEMOIZED) return totalScore;

    return totalScore = stickers[currentRow][currentColumn]
                        + max({memoizeTotalScore(currentRow - 1, (currentColumn + 1) % 2),
                               memoizeTotalScore(currentRow - 2, currentColumn),
                               memoizeTotalScore(currentRow - 2, (currentColumn + 1) % 2)});
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
