#include <iostream>

using namespace std;

int main() {
    int n;
    int k;

    cin >> n >> k;

    for (int i = 0; 2 * i <= n; i++) {
        if (i * (n - i) >= k) {
            int bRemainder = k % (n - i);

            if (!bRemainder) cout << string(i, 'A') + string(n - i, 'B');
            else cout << string(i - 1, 'A') + string(n - i - bRemainder, 'B') + 'A' + string(bRemainder, 'B');

            cout << '\n';

            return 0;
        }
    }

    cout << "-1\n";

    return 0;
}
