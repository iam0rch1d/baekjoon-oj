#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int sequenceSize;
int sequence[1000];
int maximumLengthCache[1001];

int memoizeMaximumLength(int startingAt) {
    int &maximumLength = maximumLengthCache[startingAt + 1];

    if (maximumLength != UNMEMOIZED) return maximumLength;

    maximumLength = 0;

    for (int i = startingAt + 1; i < sequenceSize; i++) {
        if (startingAt == -1 || sequence[startingAt] < sequence[i]) {
            maximumLength = max(maximumLength, memoizeMaximumLength(i) + 1);
        }
    }

    return maximumLength;
}

int main() {
    cin >> sequenceSize;

    memset(maximumLengthCache, UNMEMOIZED, sizeof(maximumLengthCache));

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];
    }

    cout << memoizeMaximumLength(-1) << endl;

    return 0;
}
