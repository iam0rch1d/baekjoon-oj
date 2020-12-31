#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int n;

    cin >> n;

    vl dp(n + 2, 0);

    dp[0] = 0;
    dp[1] = 1;

    FOR_(i, 2, n + 1) dp[i] = dp[i - 1] + dp[i - 2];

    PRINTLN(2 * (dp[n + 1] + dp[n]));

    return 0;
}
