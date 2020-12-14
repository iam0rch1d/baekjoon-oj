#include <iostream>
#include <vector>

using namespace std;

#define UNMEMOIZED -1
#define MODULO 1000000000

int memoizeStaircaseNumberCount(vector<vector<int>> &staircaseNumberCountCache,
                                int staircaseNumberSize,
                                int startingWith) {
    if (staircaseNumberSize == 1) return 1;

    if (staircaseNumberCountCache[staircaseNumberSize][startingWith] != UNMEMOIZED) {
        return staircaseNumberCountCache[staircaseNumberSize][startingWith];
    }

    int &staircaseNumberCount = staircaseNumberCountCache[staircaseNumberSize][startingWith];

    switch (startingWith) {
        case 0: {
            return staircaseNumberCount = memoizeStaircaseNumberCount(staircaseNumberCountCache,
                                                                      staircaseNumberSize - 1,
                                                                      1);
        }
        case 9: {
            return staircaseNumberCount = memoizeStaircaseNumberCount(staircaseNumberCountCache,
                                                                      staircaseNumberSize - 1,
                                                                      8);
        }
        default: {
            return staircaseNumberCount = (memoizeStaircaseNumberCount(staircaseNumberCountCache,
                                                                       staircaseNumberSize - 1,
                                                                       startingWith + 1)
                                           + memoizeStaircaseNumberCount(staircaseNumberCountCache,
                                                                         staircaseNumberSize - 1,
                                                                         startingWith - 1)) % MODULO;
        }
    }
}

int main() {
    int staircaseNumberSize;
    int staircaseNumberTotalCount = 0;

    cin >> staircaseNumberSize;

    vector<vector<int>> staircaseNumberCountCache(staircaseNumberSize + 1, vector<int>(10, UNMEMOIZED));

    for (int i = 1; i <= 9; i++) {
        staircaseNumberTotalCount += memoizeStaircaseNumberCount(staircaseNumberCountCache, staircaseNumberSize, i);
        staircaseNumberTotalCount %= MODULO;
    }

    cout << staircaseNumberTotalCount << '\n';

    return 0;
}
