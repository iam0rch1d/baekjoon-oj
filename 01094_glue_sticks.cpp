#include <iostream>

using namespace std;

int main() {
    unsigned x;

    cin >> x;
    cout << __builtin_popcount(x) << '\n';

    return 0;
}
