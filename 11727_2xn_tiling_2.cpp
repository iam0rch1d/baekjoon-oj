#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1
#define MODULO 10007

int tilingCountCache[1001];

int memoizeTilingCount(int width) {
    if (width == 1) return 1;
    else if (width == 2) return 3;

    int &tilingCount = tilingCountCache[width];

    if (tilingCount != UNKNOWN) return tilingCount;

    return tilingCount = (memoizeTilingCount(width - 1) + 2 * memoizeTilingCount(width - 2)) % MODULO;
}

int main() {
    int width;

    memset(tilingCountCache, UNKNOWN, sizeof(tilingCountCache));

    cin >> width;

    cout << memoizeTilingCount(width) << '\n';

    return 0;
}
