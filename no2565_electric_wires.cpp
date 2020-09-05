#include <algorithm>
#include <iostream>

using namespace std;

int connectionSize;
int connections[501];
int increaseLengthCache[501];

int main() {
    int fromPole;
    int maximumFromPole = 0;
    int toPole;

    cin >> connectionSize;

    for (int i = 0; i < connectionSize; i++) {
        cin >> fromPole >> toPole;

        connections[fromPole] = toPole;
        maximumFromPole = max(maximumFromPole, fromPole);
    }

    for (int i = 1; i <= maximumFromPole; i++) {
        for (int j = 0; j < i; j++) {
            if (connections[j] < connections[i] && increaseLengthCache[i] < increaseLengthCache[j] + 1) {
                increaseLengthCache[i] = increaseLengthCache[j] + 1;
            }
        }
    }

    cout << connectionSize - *max_element(increaseLengthCache, increaseLengthCache + maximumFromPole + 1) << endl;

    return 0;
}
