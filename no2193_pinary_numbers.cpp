#include <cstring>
#include <iostream>

#define UNMEMOIZED -1
#define MODULUS 1000000000

using namespace std;

long long int pinaryNumberCountCache[91][2];

long long int memoizePinaryNumberCount(int pinaryNumberSize, int startingWith) {
    if (pinaryNumberSize == 1) return 1;

    if (pinaryNumberCountCache[pinaryNumberSize][startingWith] != UNMEMOIZED) {
        return pinaryNumberCountCache[pinaryNumberSize][startingWith];
    }

    long long int &pinaryNumberCount = pinaryNumberCountCache[pinaryNumberSize][startingWith];

    return pinaryNumberCount = memoizePinaryNumberCount(pinaryNumberSize - 1, 0)
                               + (startingWith == 0 ? memoizePinaryNumberCount(pinaryNumberSize - 1, 1) : 0);
}

int main() {
    int pinaryNumberSize;

    memset(pinaryNumberCountCache, UNMEMOIZED, sizeof(pinaryNumberCountCache));

    cin >> pinaryNumberSize;

    cout << memoizePinaryNumberCount(pinaryNumberSize, 1) << endl;

    return 0;
}
