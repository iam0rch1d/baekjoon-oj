#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numRing;
    int ringRadiiGcd;

    cin >> numRing;

    vector<int> ringRadii(numRing);

    for (int &ringRadius : ringRadii) {
        cin >> ringRadius;
    }

    for (int i = 1; i < numRing; i++) {
        ringRadiiGcd = __gcd(ringRadii[0], ringRadii[i]);

        cout << ringRadii[0] / ringRadiiGcd << "/" << ringRadii[i] / ringRadiiGcd << '\n';
    }

    return 0;
}
