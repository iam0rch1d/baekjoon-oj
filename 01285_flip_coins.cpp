#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned n;
    int minTailCount = 401;

    cin >> n;

    vector<string> coins(n);

    for (auto &coinRow : coins) {
        cin >> coinRow;
    }

    for (unsigned flipRowBitset = 0; flipRowBitset < (1u << n); flipRowBitset++) {
        int tailCount = 0;

        for (int j = 0; j < n; j++) {
            int tailCountInColumn = 0;

            for (unsigned i = 0; i < n; i++) {
                char currentCoin = coins[i][j];

                if (flipRowBitset & (1u << i)) currentCoin = "HT"[currentCoin == 'H'];

                tailCountInColumn += currentCoin == 'T';
            }

            tailCount += min(tailCountInColumn, (int) n - tailCountInColumn);
        }

        minTailCount = min(minTailCount, tailCount);
    }

    cout << minTailCount << '\n';

    return 0;
}
