#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int minSquareCountCache[100001];

int memoizeMinSquareCount(int n) {
    if (n == 0) return 0;

    int &minSquareCount = minSquareCountCache[n];

    if (minSquareCount != UNMEMOIZED) return minSquareCount;

    minSquareCount = n;

    for (int i = 1; i * i <= n; i++) {
        minSquareCount = min(minSquareCount, memoizeMinSquareCount(n - i * i) + 1);
    }

    return minSquareCount;
}

int main() {
    int n;

    memset(minSquareCountCache, UNMEMOIZED, sizeof(minSquareCountCache));

    cin >> n;

    cout << memoizeMinSquareCount(n) << '\n';

    return 0;
}
