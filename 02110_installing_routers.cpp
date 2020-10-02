#include <algorithm>
#include <iostream>

using namespace std;

int numHouse;
int numNeededRouter;
int housePositions[200000];

bool canInstall(int withDistance) {
    int previousPickedHouse = housePositions[0];
    int pickedHouseCount = 1;

    for (int i = 1; i < numHouse; i++) {
        if (housePositions[i] - previousPickedHouse < withDistance) continue;

        previousPickedHouse = housePositions[i];
        pickedHouseCount++;

        if (pickedHouseCount >= numNeededRouter) return true;
    }

    return false;
}

int main() {
    int closestDistanceLow = 1;
    int closestDistanceHigh;
    int maxClosestDistance = 0;

    cin >> numHouse >> numNeededRouter;

    for (int i = 0; i < numHouse; i++) {
        cin >> housePositions[i];
    }

    sort(housePositions, housePositions + numHouse);

    closestDistanceHigh = housePositions[numHouse - 1] - housePositions[0];

    while (closestDistanceLow <= closestDistanceHigh) {
        int closestDistanceCenter = (closestDistanceLow + closestDistanceHigh) / 2;

        if (canInstall(closestDistanceCenter)) {
            maxClosestDistance = max(maxClosestDistance, closestDistanceCenter);
            closestDistanceLow = closestDistanceCenter + 1;
        } else closestDistanceHigh = closestDistanceCenter - 1;
    }

    cout << maxClosestDistance << '\n';

    return 0;
}
