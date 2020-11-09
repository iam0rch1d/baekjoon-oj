#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    cout << string(n - 1, ' ') + "*\n";

    for (int i = 2; i <= n - 1; i++) {
        cout << string(n - i, ' ') + '*' + string(2 * i - 3, ' ') + "*\n";
    }

    if (n > 1) cout << string(2 * n - 1, '*');

    return 0;
}
