#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int minimumSquareCountCache[100001];

int memoizeMinimumSquareCount(int n) {
    if (n == 0) return 0;

    int &minimumSquareCount = minimumSquareCountCache[n];

    if (minimumSquareCount != UNMEMOIZED) return minimumSquareCount;

    minimumSquareCount = 100001;

    for (int i = 1; i * i <= n; i++) {
        minimumSquareCount = min(minimumSquareCount, memoizeMinimumSquareCount(n - i * i) + 1);
    }

    return minimumSquareCount;
}

int main() {
    int n;

    memset(minimumSquareCountCache, UNMEMOIZED, sizeof(minimumSquareCountCache));

    cin >> n;

    cout << memoizeMinimumSquareCount(n) << endl;

    return 0;
}
