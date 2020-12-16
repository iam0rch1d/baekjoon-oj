#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int minSquareCountCache[100001];

int memoizeMinSquareCount(int n) {
    if (n == 0) return 0;

    int &minSquareCount = minSquareCountCache[n];

    if (minSquareCount != UNKNOWN) return minSquareCount;

    minSquareCount = n;

    for (int i = 1; i * i <= n; i++) {
        minSquareCount = min(minSquareCount, memoizeMinSquareCount(n - i * i) + 1);
    }

    return minSquareCount;
}

int main() {
    int n;

    memset(minSquareCountCache, UNKNOWN, sizeof(minSquareCountCache));

    cin >> n;

    cout << memoizeMinSquareCount(n) << '\n';

    return 0;
}
