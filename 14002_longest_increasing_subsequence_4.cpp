#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
int a[1000];
int dp[1000];
int backIndices[1000];

void tracebackLis(int index) {
    if (index == -1) return;

    tracebackLis(backIndices[index]);

    cout << a[index] << ' ';
}

int main() {
    cin >> n;

    memset(backIndices, -1, sizeof(backIndices));

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                backIndices[i] = j;
            }
        }
    }

    cout << *max_element(dp, dp + n) + 1 << '\n';

    tracebackLis((int) (max_element(dp, dp + n) - dp));

    cout << '\n';

    return 0;
}
