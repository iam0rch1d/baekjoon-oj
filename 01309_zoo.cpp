#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1
#define MODULO 9901

int cagingCountCache[100001];

int memoizeCagingCount(int size) {
    if (size == 0) return 1;
    else if (size == 1) return 3;

    int &cagingCount = cagingCountCache[size];

    if (cagingCount != UNKNOWN) return cagingCount;

    return cagingCount = (2 * memoizeCagingCount(size - 1) + memoizeCagingCount(size - 2)) % MODULO;
}

int main() {
    int size;

    memset(cagingCountCache, UNKNOWN, sizeof(cagingCountCache));

    cin >> size;
    cout << memoizeCagingCount(size) << '\n';

    return 0;
}
