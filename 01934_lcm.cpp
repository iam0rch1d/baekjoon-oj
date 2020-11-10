#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int testcases;

    cin >> testcases;

    while (testcases--) {
        int a;
        int b;

        cin >> a >> b;
        cout << a * b / __gcd(a, b) << '\n';
    }


    return 0;
}
