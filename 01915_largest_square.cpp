#include <algorithm>
#include <iostream>

using namespace std;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int a[1001][1001];
int dp[1001][1001];

int main() {
    int n;
    int m;

    cin >> n >> m;

    FOR_(i, 1, n) FOR_(j, 1, m) scanf("%1d", &a[i][j]);

    int ans = 0;

    FOR_(i, 1, n) {
        FOR_(j, 1, m) {
            if (!a[i][j]) continue;

            dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;

            chmax(ans, dp[i][j]);
        }
    }

    PRINTLN(ans * ans);

    return 0;
}
