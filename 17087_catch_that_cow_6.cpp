#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int numHider;
    int seekerPosition;
    int hiderPosition;
    int hiderDistancesGcd;

    cin >> numHider >> seekerPosition >> hiderPosition;

    hiderDistancesGcd = abs(seekerPosition - hiderPosition);
    numHider--;

    while (numHider-- > 0) {
        cin >> hiderPosition;

        hiderDistancesGcd = __gcd(hiderDistancesGcd, abs(seekerPosition - hiderPosition));
    }

    cout << hiderDistancesGcd << '\n';

    return 0;
}
