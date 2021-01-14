#include <iostream>

using namespace std;

using ll = long long;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000000009

template<typename T>
void chmodadd(T &x, T q) { x = (x + q) % MODULO; }

ll dp[1001][1001];

int main() {
    dp[0][0] = 1;

    FOR_(i, 1, 1000) {
        FOR_(j, 1, 1000) {
            chmodadd(dp[i][j], dp[i - 1][j - 1]);

            if (i >= 2) chmodadd(dp[i][j], dp[i - 2][j - 1]);

            if (i >= 3) chmodadd(dp[i][j], dp[i - 3][j - 1]);
        }
    }

    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        int m;

        cin >> n >> m;

        PRINTLN(dp[n][m]);
    }

    return 0;
}
