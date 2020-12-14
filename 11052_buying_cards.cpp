#include <cstring>
#include <iostream>

using namespace std;

#define UNMEMOIZED -1

int cardpackPrices[1001];
int maxTotalPriceCache[1001];

int memoizeMaxTotalPrice(int leftCards) {
    if (leftCards == 0) return 0;

    int &maxTotalPrice = maxTotalPriceCache[leftCards];

    if (maxTotalPrice != UNMEMOIZED) return maxTotalPrice;

    maxTotalPrice = 0;

    for (int i = leftCards; i > 0; i--) {
        maxTotalPrice = max(maxTotalPrice, cardpackPrices[i] + memoizeMaxTotalPrice(leftCards - i));
    }

    return maxTotalPrice;
}

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cardpackPrices[i];
    }

    memset(maxTotalPriceCache, UNMEMOIZED, sizeof(maxTotalPriceCache));

    cout << memoizeMaxTotalPrice(n) << '\n';

    return 0;
}
