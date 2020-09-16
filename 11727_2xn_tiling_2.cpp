#include <cstring>
#include <iostream>

#define UNMEMOIZED -1
#define MODULO 10007

using namespace std;

int tilingCountCache[1001];

int memoizeTilingCount(int width) {
    if (width == 1) return 1;

    if (width == 2) return 3;

    int &tilingCount = tilingCountCache[width];

    if (tilingCount != UNMEMOIZED) return tilingCount;

    return tilingCount = (memoizeTilingCount(width - 1) + 2 * memoizeTilingCount(width - 2)) % MODULO;
}

int main() {
    int width;

    memset(tilingCountCache, UNMEMOIZED, sizeof(tilingCountCache));

    cin >> width;

    cout << memoizeTilingCount(width) << endl;

    return 0;
}
