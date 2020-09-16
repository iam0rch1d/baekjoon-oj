#include <cstring>
#include <iostream>

#define UNMEMOIZED -1

using namespace std;

int cardpackPrices[10001];
int maximumTotalPriceCache[10001];

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
    int numCardpack;

    cin >> numCardpack;

    for (int i = 1; i <= numCardpack; i++) {
        cin >> cardpackPrices[i];
    }

    memset(maximumTotalPriceCache, UNMEMOIZED, sizeof(maximumTotalPriceCache));

    cout << memoizeMaximumTotalPrice(numCardpack) << endl;

    return 0;
}
