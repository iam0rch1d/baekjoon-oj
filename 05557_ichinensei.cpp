#include <iostream>

using namespace std;

int numbers[99];
int lastNumber;
long long dp[99][21];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> numbers[i];
    }

    cin >> lastNumber;

    dp[0][numbers[0]] = 1;

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i][j]) {
                if (j - numbers[i + 1] >= 0) dp[i + 1][j - numbers[i + 1]] += dp[i][j];

                if (j + numbers[i + 1] <= 20) dp[i + 1][j + numbers[i + 1]] += dp[i][j];
            }
        }
    }

    cout << dp[n - 2][lastNumber] << '\n';

    return 0;
}
