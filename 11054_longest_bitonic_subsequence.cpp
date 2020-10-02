#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int sequenceSize;
    int sequence[1000];
    int increaseLengthCache[1000];
    int decreaseLengthCache[1000];
    priority_queue<int> bitonicLengths;

    memset(increaseLengthCache, 0, sizeof(increaseLengthCache));
    memset(decreaseLengthCache, 0, sizeof(decreaseLengthCache));
    bitonicLengths.push(1);

    cin >> sequenceSize;

    for (int i = 0; i < sequenceSize; i++) {
        cin >> sequence[i];

        increaseLengthCache[i] = 1;
        decreaseLengthCache[i] = 1;
    }

    for (int i = 1; i < sequenceSize; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i] && increaseLengthCache[i] < increaseLengthCache[j]) {
                increaseLengthCache[i] = increaseLengthCache[j] + 1;
            }
        }
    }

    for (int i = sequenceSize - 2; i > 0; i--) {
        for (int j = sequenceSize - 1; j > i; j--) {
            if (sequence[j] < sequence[i] && decreaseLengthCache[i] < decreaseLengthCache[j]) {
                decreaseLengthCache[i] = decreaseLengthCache[j] + 1;
            }
        }

        bitonicLengths.push(increaseLengthCache[i] + decreaseLengthCache[i] - 1);
    }

    cout << bitonicLengths.top() << '\n';

    return 0;
}
