#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int sequenceSize;
    int sequence[100002];
    int sequenceSum = 0;

    // 'CS' refers to 'Continuous Sum'
    int toIndexMaxCsCache[100002];
    int fromIndexMaxCsCache[100002];
    int removedOneMaxCsCache[100002];

    cin >> sequenceSize;

    toIndexMaxCsCache[0] = -1001;

    for (int i = 1; i <= sequenceSize; i++) {
        cin >> sequence[i];

        sequenceSum += sequence[i];
        toIndexMaxCsCache[i] = sequence[i] + max(toIndexMaxCsCache[i - 1], 0);
    }

    fromIndexMaxCsCache[sequenceSize + 1] = -1001;

    for (int i = sequenceSize; i >= 0; i--) {
        fromIndexMaxCsCache[i] = sequence[i] + max(fromIndexMaxCsCache[i + 1], 0);
    }

    for (int i = 1; i <= sequenceSize; i++) {
        removedOneMaxCsCache[i] = max({toIndexMaxCsCache[i - 1] + fromIndexMaxCsCache[i + 1],
                                       toIndexMaxCsCache[i - 1],
                                       fromIndexMaxCsCache[i + 1]});
    }

    cout << max(sequenceSum, *max_element(removedOneMaxCsCache + 1, removedOneMaxCsCache + sequenceSize + 1)) << '\n';

    return 0;
}
