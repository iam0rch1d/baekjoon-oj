#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    int k;
    int teams = 0;

    cin >> n >> m >> k;

    while (n >= 2 && m >= 1 && n + m >= k + 3) {
        n -= 2;
        m -= 1;
        teams++;
    }

    cout << teams << '\n';

    return 0;
}
