#include <iostream>

using namespace std;

void dncMoveDisc(unsigned size, int fromPeg, int auxPeg, int toPeg) {
    if (!size) return;

    dncMoveDisc(size - 1, fromPeg, toPeg, auxPeg);

    cout << fromPeg << ' ' << toPeg << '\n';

    dncMoveDisc(size - 1, auxPeg, fromPeg, toPeg);
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    unsigned n;

    cin >> n;
    cout << (1u << n) - 1u << '\n';

    dncMoveDisc(n, 1, 2, 3);

    return 0;
}
