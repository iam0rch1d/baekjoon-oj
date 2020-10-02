#include <algorithm>
#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int sequenceSize;
int sequence[1001];
int maxLengthCache[1001];

int memoizeMaxLength(int toIndex) {
    int &maxLength = maxLengthCache[toIndex];

    if (maxLength != UNMEMOIZED) return maxLength;

    maxLength = 0;

    for (int i = toIndex - 1; i >= 0; i--) {
        if (sequence[i] < sequence[toIndex]) maxLength = max(maxLength, memoizeMaxLength(i));
    }

    return ++maxLength;
}

int main() {
    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    memset(maxLengthCache, UNMEMOIZED, sizeof(maxLengthCache));

    sequence[sequenceSize] = 1001;

    cout << memoizeMaxLength(sequenceSize) - 1 << '\n';

    return 0;
}
