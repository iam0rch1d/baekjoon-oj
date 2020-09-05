#include <iostream>
#include <queue>

using namespace std;

int connectionSize;
int connections[1000];
int increaseLengthCache[1000];
int decreaseLengthCache[1000];

int main() {
    priority_queue<int> bitonicLengths;

    bitonicLengths.push(1);

    cin >> connectionSize;

    for (int i = 0; i < connectionSize; i++) {
        cin >> connections[i];

        increaseLengthCache[i] = 1;
        decreaseLengthCache[i] = 1;
    }

    for (int i = 1; i < connectionSize; i++) {
        for (int j = 0; j < i; j++) {
            if (connections[j] < connections[i] && increaseLengthCache[i] < increaseLengthCache[j] + 1) {
                increaseLengthCache[i] = increaseLengthCache[j] + 1;
            }
        }
    }

    for (int i = connectionSize - 2; i > 0; i--) {
        for (int j = connectionSize - 1; j > i; j--) {
            if (connections[j] < connections[i] && decreaseLengthCache[i] < decreaseLengthCache[j] + 1) {
                decreaseLengthCache[i] = decreaseLengthCache[j] + 1;
            }
        }

        bitonicLengths.push(increaseLengthCache[i] + decreaseLengthCache[i] - 1);
    }

    cout << bitonicLengths.top() << endl;

    return 0;
}
