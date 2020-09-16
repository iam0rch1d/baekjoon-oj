#include <algorithm>
#include <iostream>

using namespace std;

int maximumContinuousSumCache[100001] = {-1001};

int main() {
    int sequenceSize;
    int sequence[100000];

    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];

        maximumContinuousSumCache[i + 1] = max(maximumContinuousSumCache[i] + sequence[i], sequence[i]);
    }

    cout << *max_element(maximumContinuousSumCache, maximumContinuousSumCache + sequenceSize + 1) << endl;

    return 0;
}
