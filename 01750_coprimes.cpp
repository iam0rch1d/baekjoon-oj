#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 10000003

template<typename T>
void chmodadd(T &x, T q) { x = (x + q) % MODULO; }

int a[101];
ll dp[101][100001];

int main() {
    int n;

    cin >> n;

    FOR_(i, 1, n) cin >> a[i];

    FOR_(i, 1, n) {
        dp[i][a[i]]++;

        FOR_(j, 1, 100000) {
            if (!dp[i - 1][j]) continue;

            chmodadd(dp[i][j], dp[i - 1][j]);
            chmodadd(dp[i][__gcd(j, a[i])], dp[i - 1][j]);
        }
    }

    PRINTLN(dp[n][1]);

    return 0;
}
