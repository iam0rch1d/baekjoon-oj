#include <cstring>
#include <iostream>

using namespace std;

#define UNMEMOIZED -1
#define MODULO 1000000000

long long pinaryNumberCountCache[91][2];

long long memoizePinaryNumberCount(int pinaryNumberSize, int startingWith) {
    if (pinaryNumberSize == 1) return 1;

    long long &pinaryNumberCount = pinaryNumberCountCache[pinaryNumberSize][startingWith];

    if (pinaryNumberCount != UNMEMOIZED) return pinaryNumberCount;

    return pinaryNumberCount = memoizePinaryNumberCount(pinaryNumberSize - 1, 0)
                               + (startingWith == 0 ? memoizePinaryNumberCount(pinaryNumberSize - 1, 1) : 0);
}

int main() {
    int pinaryNumberSize;

    memset(pinaryNumberCountCache, UNMEMOIZED, sizeof(pinaryNumberCountCache));

    cin >> pinaryNumberSize;

    cout << memoizePinaryNumberCount(pinaryNumberSize, 1) << '\n';

    return 0;
}
