#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int a;
        int b;

        cin >> a >> b;
        cout << a * b / __gcd(a, b) << '\n';
    }


    return 0;
}
