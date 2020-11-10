#include <iostream>

using namespace std;

void dncMoveDisc(unsigned size, int fromPeg, int auxiliaryPeg, int toPeg) {
    if (size == 1) {
        cout << fromPeg << ' ' << toPeg << '\n';

        return;
    }

    dncMoveDisc(size - 1, fromPeg, toPeg, auxiliaryPeg);

    cout << fromPeg << ' ' << toPeg << '\n';

    dncMoveDisc(size - 1, auxiliaryPeg, fromPeg, toPeg);
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
