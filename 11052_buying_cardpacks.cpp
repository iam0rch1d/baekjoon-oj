#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int cardpackPrices[1001];
int maximumTotalPriceCache[1001];

int memoizeMaximumTotalPrice(int leftCards) {
    if (leftCards == 0) return 0;

    int &maximumTotalPrice = maximumTotalPriceCache[leftCards];

    if (maximumTotalPrice != UNMEMOIZED) return maximumTotalPrice;

    maximumTotalPrice = 0;

    for (int i = leftCards; i > 0; i--) {
        maximumTotalPrice = max(maximumTotalPrice, cardpackPrices[i] + memoizeMaximumTotalPrice(leftCards - i));
    }

    return maximumTotalPrice;
}

int main() {
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cardpackPrices[i];
    }

    memset(maximumTotalPriceCache, UNMEMOIZED, sizeof(maximumTotalPriceCache));

    cout << memoizeMaximumTotalPrice(n) << endl;

    return 0;
}
