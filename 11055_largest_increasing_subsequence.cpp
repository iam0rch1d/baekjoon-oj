#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int n;
int a[1001];
int maxSumCache[1001];

int memoizeMaxSum(int toIndex) {
    if (toIndex == 0) return a[0];

    int &maxSum = maxSumCache[toIndex];

    if (maxSum != UNMEMOIZED) return maxSum;

    maxSum = 0;

    for (int i = toIndex - 1; i >= 0; i--) {
        if (a[i] < a[toIndex]) maxSum = max(maxSum, memoizeMaxSum(i));
    }

    return maxSum += a[toIndex];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    a[n] = 1e6;

    memset(maxSumCache, UNMEMOIZED, sizeof(maxSumCache));

    cout << memoizeMaxSum(n) - 1e6 << '\n';

    return 0;
}
