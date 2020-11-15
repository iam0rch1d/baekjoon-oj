#include <algorithm>
#include <iostream>

using namespace std;

long long whiteCards[50001];
long long whiteCardSums[50001];
long long blackCards[50001];
long long blackCardSums[50001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long maxCardSum;

    cin >> n;

    for (int i = 1; 2 * i <= n; i++) {
        cin >> whiteCards[i] >> blackCards[i];

        whiteCardSums[i] = whiteCardSums[i - 1] + whiteCards[i];
        blackCardSums[i] = blackCardSums[i - 1] + blackCards[i];
    }

    maxCardSum = max(whiteCardSums[n / 2], blackCardSums[n / 2]);

    for (int i = 1; 2 * i <= n; i++) {
        maxCardSum = max({maxCardSum,
                          whiteCardSums[i] + blackCardSums[n / 2] - blackCardSums[i],
                          whiteCardSums[i] + blackCardSums[n / 2 - 1] - blackCardSums[i - 1]});
    }

    cout << maxCardSum << '\n';

    return 0;
}
