#include <iostream>

using namespace std;

int main() {
    int n;
    int k;
    int bkLeft = 1;
    int bkRight;
    int bk;

    cin >> n >> k;

    bkRight = k;

    while (bkLeft <= bkRight) {
        int bkMid = (bkLeft + bkRight) / 2;
        int belowBkMidNumbers = 0;

        for (int i = 1; i <= n; i++) {
            belowBkMidNumbers += min(bkMid / i, n);
        }

        if (belowBkMidNumbers < k) bkLeft = bkMid + 1;
        else {
            bk = bkMid;
            bkRight = bkMid - 1;
        }
    }

    cout << bk << '\n';

    return 0;
}
