#include <iostream>

using namespace std;

int main() {
    long long a;
    long long b;
    long long c;
    long long x;
    long long y;
    long long totalCost = 0x7fffffff;

    cin >> a >> b >> c >> x >> y;

    for (long long i = 0; i <= 100000; i++) {
        totalCost = min(totalCost, max(x - i, 0ll) * a + max(y - i, 0ll) * b + 2 * i * c);
    }

    cout << totalCost << '\n';

    return 0;
}
