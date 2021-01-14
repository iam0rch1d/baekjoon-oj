#include <iostream>

using namespace std;

using ll = long long;

#define FOR_(i, x, y) for (ll i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000000007

template<typename T>
void chmodadd(T &x, T q) { x = (x + q) % MODULO; }

ll dp[101][101][101];

int main() {
    ll n;
    int l;
    int r;

    cin >> n >> l >> r;

    dp[1][1][1] = 1;

    FOR_(i, 1, n - 1) {
        FOR_(j, 1, l) {
            FOR_(k, 1, r) {
                chmodadd(dp[i + 1][j + 1][k], dp[i][j][k]);
                chmodadd(dp[i + 1][j][k + 1], dp[i][j][k]);
                chmodadd(dp[i + 1][j][k], dp[i][j][k] * (i - 1) % MODULO);
            }
        }
    }

    PRINTLN(dp[n][l][r]);

    return 0;
}
