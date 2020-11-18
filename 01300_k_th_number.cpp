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
        int belowBkMidCount = 0;

        for (int i = 1; i <= n; i++) {
            belowBkMidCount += min(bkMid / i, n);
        }

        if (belowBkMidCount < k) bkLeft = bkMid + 1;
        else {
            bk = bkMid;
            bkRight = bkMid - 1;
        }
    }

    cout << bk << '\n';

    return 0;
}
