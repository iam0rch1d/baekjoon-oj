#include <cstring>
#include <iostream>

#define UNMEMOIZED -1
#define MODULO 1000000000

using namespace std;

long long divisionCount[201];

int main() {
    int n;
    int k;

    cin >> n >> k;

    divisionCount[0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            divisionCount[j] = (divisionCount[j] + divisionCount[j - 1]) % MODULO;
        }
    }

    cout << divisionCount[n] << '\n';

    return 0;
}
