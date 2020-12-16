#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int cardpackPrices[1001];
int minTotalPriceCache[1001];

int memoizeMinTotalPrice(int leftCards) {
    if (leftCards == 0) return 0;

    int &minTotalPrice = minTotalPriceCache[leftCards];

    if (minTotalPrice != UNKNOWN) return minTotalPrice;

    minTotalPrice = 100000001;

    for (int i = leftCards; i > 0; i--) {
        minTotalPrice = min(minTotalPrice, cardpackPrices[i] + memoizeMinTotalPrice(leftCards - i));
    }

    return minTotalPrice;
}

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cardpackPrices[i];
    }

    memset(minTotalPriceCache, UNKNOWN, sizeof(minTotalPriceCache));

    cout << memoizeMinTotalPrice(n) << '\n';

    return 0;
}
