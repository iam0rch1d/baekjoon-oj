#include <iostream>

using namespace std;

int main() {
    long long n;
    long long m;

    cin >> n >> m;
    cout << (n == 1 ? 1 : n == 2 ? min((m + 1) / 2, 4ll) : m >= 7 ? m - 2 : min(m, 4ll)) << '\n';

    return 0;
}
