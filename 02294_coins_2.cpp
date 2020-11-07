#include <iostream>
#include <vector>

using namespace std;

int coinCountCache[100001];

int main() {
    int n;
    int k;

    cin >> n >> k;

    vector<int> coinValues(n);

    for (int &coinValue : coinValues) {
        cin >> coinValue;
    }

    for (int &coinCount : coinCountCache) {
        coinCount = 100001;
    }

    coinCountCache[0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            int previousTotalValue = i - coinValues[j];

            if (previousTotalValue < 0) continue;

            coinCountCache[i] = min(coinCountCache[i], coinCountCache[previousTotalValue] + 1);
        }
    }

    cout << (coinCountCache[k] == 100001 ? -1 : coinCountCache[k] - 1) << '\n';

    return 0;
}
