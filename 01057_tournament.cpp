#include <iostream>

using namespace std;

int main() {
    unsigned n;
    unsigned x;
    unsigned y;
    unsigned round;

    cin >> n >> x >> y;

    x--;
    y--;

    for (unsigned i = 0; (1u << i) < n; i++) {
        if ((x & (1u << i)) ^ (y & (1u << i))) round = i + 1;
    }

    cout << round << '\n';

    return 0;
}
