#include <algorithm>
#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int sequenceSize;
int sequence[1001];
int maxLengthCache[1001];
int triggerIndexCache[1001];

int memoizeMaxLength(int toIndex) {
    int &maxLength = maxLengthCache[toIndex];

    if (maxLength != UNMEMOIZED) return maxLength;

    maxLength = 0;

    for (int i = toIndex - 1; i >= 0; i--) {
        if (sequence[i] < sequence[toIndex] && memoizeMaxLength(i) >= maxLength) {
            maxLength = memoizeMaxLength(i);
            triggerIndexCache[toIndex] = i;
        }
    }

    return ++maxLength;
}

void tracebackLis(int index) {
    if (index == -1) return;

    tracebackLis(triggerIndexCache[index]);

    if (index == sequenceSize) return;

    cout << sequence[index] << ' ';
}

int main() {
    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    sequence[sequenceSize] = 1001;

    memset(maxLengthCache, UNMEMOIZED, sizeof(maxLengthCache));
    memset(triggerIndexCache, UNMEMOIZED, sizeof(triggerIndexCache));

    cout << memoizeMaxLength(sequenceSize) - 1 << '\n';

    tracebackLis(sequenceSize);

    cout << '\n';

    return 0;
}
