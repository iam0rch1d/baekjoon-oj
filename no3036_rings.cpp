#include <iostream>
#include <vector>

using namespace std;

int euclid(int a, int b) {
    if (b > a) return euclid(b, a);

    if (a % b == 0) return b;

    return euclid(b, a - b);
}

int main() {
    int numRing;
    int ringRadiiGcd;

    cin >> numRing;

    vector<int> ringRadii(numRing);

    for (int i = 0; i < numRing; i++) {
        cin >> ringRadii[i];
    }

    for (int i = 1; i < numRing; i++) {
        ringRadiiGcd = euclid(ringRadii[0], ringRadii[i]);

        cout << ringRadii[0] / ringRadiiGcd << "/" << ringRadii[i] / ringRadiiGcd << endl;
    }

    return 0;
}
