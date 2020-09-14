#include <iostream>

using namespace std;

int main() {
    int n;
    int k;
    int bkLow = 1;
    int bkHigh;
    int bk;

    cin >> n >> k;

    bkHigh = n * n;

    while (bkLow <= bkHigh) {
        int bkCenter = (bkLow + bkHigh) / 2;
        long long lessThanKCount = 0;

        for (int i = 1; i <= n; i++) {
            lessThanKCount += min(bkCenter / i, n);
        }

        if (lessThanKCount < k) bkLow = bkCenter + 1;
        else {
            bk = bkCenter;
            bkHigh = bkCenter - 1;
        }
    }

    cout << bk << endl;

    return 0;
}
