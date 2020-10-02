#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int sequenceSize;
int sequence[1001];
int maximumSumCache[1001];

int memoizeMaximumSum(int toIndex) {
    if (toIndex == 0) return sequence[0];

    int &maximumSum = maximumSumCache[toIndex];

    if (maximumSum != UNMEMOIZED) return maximumSum;

    maximumSum = 0;

    for (int i = toIndex - 1; i >= 0; i--) {
        if (sequence[i] < sequence[toIndex]) maximumSum = max(maximumSum, memoizeMaximumSum(i));
    }

    return maximumSum += sequence[toIndex];
}

int main() {
    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    sequence[sequenceSize] = 1e6;

    memset(maximumSumCache, UNMEMOIZED, sizeof(maximumSumCache));

    cout << memoizeMaximumSum(sequenceSize) - 1e6 << '\n';

    return 0;
}
