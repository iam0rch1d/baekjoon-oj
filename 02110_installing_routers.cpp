#include <algorithm>
#include <iostream>

using namespace std;

int n;
int c;
int x[200000];

bool canInstall(int withDistance) {
    int lastPickedXi = x[0];
    int pickedXiCount = 1;

    for (int i = 1; i < n; i++) {
        if (x[i] - lastPickedXi < withDistance) continue;

        lastPickedXi = x[i];
        pickedXiCount++;

        if (pickedXiCount >= c) return true;
    }

    return false;
}

int main() {
    int closestDistanceLeft = 1;
    int closestDistanceRight;
    int closestDistance;

    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    closestDistanceRight = x[n - 1] - x[0];

    while (closestDistanceLeft <= closestDistanceRight) {
        int closestDistanceMid = (closestDistanceLeft + closestDistanceRight) / 2;

        if (canInstall(closestDistanceMid)) {
            closestDistance = closestDistanceMid;
            closestDistanceLeft = closestDistanceMid + 1;
        } else closestDistanceRight = closestDistanceMid - 1;
    }

    cout << closestDistance << '\n';

    return 0;
}
