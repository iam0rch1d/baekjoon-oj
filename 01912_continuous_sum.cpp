#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int sequenceSize;
    int sequence[100000];
    int maxContinuousSumCache[100000];

    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];

        maxContinuousSumCache[i] = sequence[i] + (i == 0 ? 0 : max(maxContinuousSumCache[i - 1], 0));
    }

    cout << *max_element(maxContinuousSumCache, maxContinuousSumCache + sequenceSize) << '\n';

    return 0;
}
