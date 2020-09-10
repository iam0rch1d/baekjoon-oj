#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int connectionsSize;
    int connections[501];
    int fromPole;
    int toPole;
    int maximumFromPole = 0;
    int increaseLengthCache[501];

    cin >> connectionsSize;

    memset(connections, 0, sizeof(connections));

    for (int i = 0; i < connectionsSize; i++) {
        cin >> fromPole >> toPole;

        connections[fromPole] = toPole;
        maximumFromPole = max(maximumFromPole, fromPole);
    }

    memset(increaseLengthCache, 0, sizeof(increaseLengthCache));

    for (int i = 1; i <= maximumFromPole; i++) {
        for (int j = 0; j < i; j++) {
            if (connections[j] < connections[i] && increaseLengthCache[i] < increaseLengthCache[j] + 1) {
                increaseLengthCache[i] = increaseLengthCache[j] + 1;
            }
        }
    }

    cout << connectionsSize - *max_element(increaseLengthCache, increaseLengthCache + maximumFromPole + 1) << endl;

    return 0;
}
