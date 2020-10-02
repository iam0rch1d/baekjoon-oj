#include <algorithm>
#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int sequenceSize;
int sequence[1001];
int maximumLengthCache[1001];

int memoizeMaximumLength(int toIndex) {
    int &maximumLength = maximumLengthCache[toIndex];

    if (maximumLength != UNMEMOIZED) return maximumLength;

    maximumLength = 0;

    for (int i = toIndex - 1; i >= 0; i--) {
        if (sequence[i] < sequence[toIndex]) maximumLength = max(maximumLength, memoizeMaximumLength(i));
    }

    return ++maximumLength;
}

int main() {
    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    memset(maximumLengthCache, UNMEMOIZED, sizeof(maximumLengthCache));

    sequence[sequenceSize] = 1001;

    cout << memoizeMaximumLength(sequenceSize) - 1 << '\n';

    return 0;
}
