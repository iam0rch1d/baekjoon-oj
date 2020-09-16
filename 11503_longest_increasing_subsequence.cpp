#include <iostream>
#include <vector>

#define UNMEMOIZED -1

using namespace std;

int memoizeMaximumLength(const vector<int> &sequence, vector<int> &maximumLengthCache, int startingAt) {
    int &maximumLength = maximumLengthCache[startingAt + 1];

    if (maximumLength != UNMEMOIZED) return maximumLength;

    maximumLength = 1;

    for (int i = startingAt + 1; i < sequence.size(); i++) {
        if (startingAt == -1 || sequence[startingAt] < sequence[i]) {
            maximumLength = max(maximumLength, memoizeMaximumLength(sequence, maximumLengthCache, i) + 1);
        }
    }

    return maximumLength;
}

int main() {
    int sequenceSize;

    cin >> sequenceSize;

    vector<int> sequence(sequenceSize);
    vector<int> maximumLengthCache(sequenceSize + 1, UNMEMOIZED);

    for (int &element : sequence) {
        cin >> element;
    }

    cout << memoizeMaximumLength(sequence, maximumLengthCache, -1) - 1 << endl;

    return 0;
}
