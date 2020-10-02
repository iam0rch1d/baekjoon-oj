#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int sequenceSize;
int sequence[1001];
int maxSumCache[1001];

int memoizeMaxSum(int toIndex) {
    if (toIndex == 0) return sequence[0];

    int &maxSum = maxSumCache[toIndex];

    if (maxSum != UNMEMOIZED) return maxSum;

    maxSum = 0;

    for (int i = toIndex - 1; i >= 0; i--) {
        if (sequence[i] < sequence[toIndex]) maxSum = max(maxSum, memoizeMaxSum(i));
    }

    return maxSum += sequence[toIndex];
}

int main() {
    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    sequence[sequenceSize] = 1e6;

    memset(maxSumCache, UNMEMOIZED, sizeof(maxSumCache));

    cout << memoizeMaxSum(sequenceSize) - 1e6 << '\n';

    return 0;
}
