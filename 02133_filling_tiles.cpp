#include <cstring>
#include <iostream>

using namespace std;

#define UNMEMOIZED -1

int tilingCountCache[16];

int memoizeTilingCount(int width) {
    if (width == 0) return 1;

    int &tilingCount = tilingCountCache[width / 2];

    if (tilingCount != UNMEMOIZED) return tilingCount;

    tilingCount = 3 * memoizeTilingCount(width - 2);

    for (int i = width - 4; i >= 0; i -= 2) {
        tilingCount += 2 * memoizeTilingCount(i);
    }

    return tilingCount;
}

int main() {
    int width;

    memset(tilingCountCache, UNMEMOIZED, sizeof(tilingCountCache));

    cin >> width;

    if (width % 2 != 0) {
        cout << "0\n";

        return 0;
    }

    cout << memoizeTilingCount(width) << '\n';

    return 0;
}
