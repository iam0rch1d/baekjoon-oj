#include <algorithm>
#include <iostream>

using namespace std;

long long dp[21][21];

int main() {
    int n;
    int m;
    long long numerator = 0;
    long long denominator = 1;
    long long gcd;

    cin >> n >> m;

    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        numerator += dp[n][i];
    }

    for (long long i = 2; i <= n; i++) {
        denominator *= i;
    }

    gcd = __gcd(numerator, denominator);

    cout << numerator / gcd << '/' << denominator / gcd << '\n';

    return 0;
}
