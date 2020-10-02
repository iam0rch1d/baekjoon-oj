#include <algorithm>
#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int sequenceSize;
int sequence[1001];
int maximumLengthCache[1001];
int triggerIndexCache[1001];

int memoizeMaximumLength(int toIndex) {
    int &maximumLength = maximumLengthCache[toIndex];

    if (maximumLength != UNMEMOIZED) return maximumLength;

    maximumLength = 0;

    for (int i = toIndex - 1; i >= 0; i--) {
        if (sequence[i] < sequence[toIndex] && memoizeMaximumLength(i) >= maximumLength) {
            maximumLength = memoizeMaximumLength(i);
            triggerIndexCache[toIndex] = i;
        }
    }

    return ++maximumLength;
}

void backtrackLis(int index) {
    if (index == -1) return;

    backtrackLis(triggerIndexCache[index]);

    if (index == sequenceSize) return;

    cout << sequence[index] << ' ';
}

int main() {
    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    sequence[sequenceSize] = 1001;

    memset(maximumLengthCache, UNMEMOIZED, sizeof(maximumLengthCache));
    memset(triggerIndexCache, UNMEMOIZED, sizeof(triggerIndexCache));

    cout << memoizeMaximumLength(sequenceSize) - 1 << '\n';

    backtrackLis(sequenceSize);

    cout << '\n';

    return 0;
}
