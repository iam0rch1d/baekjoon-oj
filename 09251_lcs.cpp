#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
    string a;
    string b;
    int aSize;
    int bSize;

    cin >> a >> b;

    aSize = a.size();
    bSize = b.size();

    a = ' ' + a;
    b = ' ' + b;

    for (int i = 1; i <= aSize; i++) {
        for (int j = 1; j <= bSize; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[aSize][bSize] << '\n';

    return 0;
}
