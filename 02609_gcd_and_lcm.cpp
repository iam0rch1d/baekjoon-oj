#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    int gcd;

    cin >> a >> b;

    gcd = __gcd(a, b);

    cout << gcd << endl << a * b / gcd << endl;

    return 0;
}
