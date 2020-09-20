#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int cardpackPrices[1001];
int minimumTotalPriceCache[1001];

int memoizeMinimumTotalPrice(int leftCards) {
    if (leftCards == 0) return 0;

    int &minimumTotalPrice = minimumTotalPriceCache[leftCards];

    if (minimumTotalPrice != UNMEMOIZED) return minimumTotalPrice;

    minimumTotalPrice = 100000001;

    for (int i = leftCards; i > 0; i--) {
        minimumTotalPrice = min(minimumTotalPrice, cardpackPrices[i] + memoizeMinimumTotalPrice(leftCards - i));
    }

    return minimumTotalPrice;
}

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cardpackPrices[i];
    }

    memset(minimumTotalPriceCache, UNMEMOIZED, sizeof(minimumTotalPriceCache));

    cout << memoizeMinimumTotalPrice(n) << endl;

    return 0;
}
