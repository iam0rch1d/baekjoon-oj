#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int a;
        int b;

        cin >> a >> b;
        cout << a * b / __gcd(a, b) << '\n';
    }

    return 0;
}
