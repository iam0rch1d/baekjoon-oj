#include <iostream>

using namespace std;

int main() {
    int n;
    int k;
    int bkLow = 1;
    int bkHigh;
    int bk;

    cin >> n >> k;

    bkHigh = k;

    while (bkLow <= bkHigh) {
        int bkCenter = (bkLow + bkHigh) / 2;
        int belowBkCenterCount = 0;

        for (int i = 1; i <= n; i++) {
            belowBkCenterCount += min(bkCenter / i, n);
        }

        if (belowBkCenterCount < k) bkLow = bkCenter + 1;
        else {
            bk = bkCenter;
            bkHigh = bkCenter - 1;
        }
    }

    cout << bk << endl;

    return 0;
}
