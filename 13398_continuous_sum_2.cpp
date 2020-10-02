#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int sequenceSize;
    int sequence[100000];

    // 'CS' refers to 'Continuous Sum'
    int toIndexMaxCsCache[100000];
    int fromIndexMaxCsCache[100000];
    int removedOneMaxCsCache[100000];

    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];

        toIndexMaxCsCache[i] = sequence[i] + (i == 0 ? 0 : max(toIndexMaxCsCache[i - 1], 0));
    }

    for (int i = sequenceSize - 1; i >= 0; i--) {
        fromIndexMaxCsCache[i] = sequence[i] + (i == sequenceSize - 1 ? 0 : max(fromIndexMaxCsCache[i + 1], 0));
    }

    for (int i = 1; i <= sequenceSize - 2; i++) {
        removedOneMaxCsCache[i] = toIndexMaxCsCache[i - 1] + fromIndexMaxCsCache[i + 1];
    }

    cout << (sequenceSize >= 3 ? max(*max_element(toIndexMaxCsCache, toIndexMaxCsCache + sequenceSize),
                                     *max_element(removedOneMaxCsCache + 1, removedOneMaxCsCache + sequenceSize - 1))
                               : *max_element(toIndexMaxCsCache, toIndexMaxCsCache + sequenceSize))
         << '\n';

    return 0;
}
