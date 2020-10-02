#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int numOwnedCable;
    long long numNeededCable;
    long long ownedCables[10000];
    long long croppingSizeLow = 1;
    long long croppingSizeHigh;
    long long maxCroppingSize = 0;

    cin >> numOwnedCable >> numNeededCable;

    for (int i = 0; i < numOwnedCable; i++) {
        cin >> ownedCables[i];
    }

    croppingSizeHigh = *max_element(ownedCables, ownedCables + numOwnedCable);

    while (croppingSizeLow <= croppingSizeHigh) {
        long long croppedCableCount = 0;
        long long croppingSizeCenter = (croppingSizeLow + croppingSizeHigh) / 2;

        for (int i = 0; i < numOwnedCable; i++) {
            croppedCableCount += ownedCables[i] / croppingSizeCenter;
        }

        if (croppedCableCount >= numNeededCable) {
            maxCroppingSize = max(maxCroppingSize, croppingSizeCenter);
            croppingSizeLow = croppingSizeCenter + 1;
        } else croppingSizeHigh = croppingSizeCenter - 1;
    }

    cout << maxCroppingSize << '\n';

    return 0;
}
