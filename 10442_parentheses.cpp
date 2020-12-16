#include <iostream>

using namespace std;

#define MODULO 1000000007

long long vpsCountCache[5001];

int main() {
    int t;

    vpsCountCache[0] = 1;

    for (int i = 2; i <= 5000; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            vpsCountCache[i] = (vpsCountCache[i] + vpsCountCache[j - 2] * vpsCountCache[i - j] % MODULO) % MODULO;
        }
    }

    cin >> t;

    while (t--) {
        int l;

        cin >> l;
        cout << vpsCountCache[l] << '\n';
    }

    return 0;
}
