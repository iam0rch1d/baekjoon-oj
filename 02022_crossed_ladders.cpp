#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double x;
    double y;
    double c;
    double distanceLeft = 0;
    double distanceRight;

    cin >> x >> y >> c;

    distanceRight = min(x, y);

    while (abs(distanceRight - distanceLeft) > 1e-6) {
        double distanceMid = (distanceLeft + distanceRight) / 2;
        double h1 = sqrt(x * x - distanceMid * distanceMid);
        double h2 = sqrt(y * y - distanceMid * distanceMid);

        if (h1 * h2 / (h1 + h2) > c) distanceLeft = distanceMid;
        else distanceRight = distanceMid;
    }

    cout << fixed << (distanceLeft + distanceRight) / 2 << '\n';

    return 0;
}
