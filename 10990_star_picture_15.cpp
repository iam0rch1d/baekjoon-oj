#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << string(n - i, ' ') + '*' + (i >= 2 ? string(2 * i - 3, ' ') + "*\n" : "\n");
    }

    return 0;
}
