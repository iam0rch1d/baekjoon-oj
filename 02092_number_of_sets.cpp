#include <iostream>

using namespace std;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000000

template<typename T>
void chmodadd(T &x, T q) { x = (x + q) % MODULO; }

int counts[201];
int dp[201][4001];

int main() {
    int t;
    int a;
    int s;
    int b;

    cin >> t >> a >> s >> b;

    REP(i, a) {
        int element;

        cin >> element;

        counts[element]++;
    }

    dp[0][0] = 1;

    FOR_(i, 1, t) {
        dp[i][0] = 1;

        FOR_(j, 1, a) FOR_(k, 0, counts[i]) if (j - k >= 0) chmodadd(dp[i][j], dp[i - 1][j - k]);
    }

    int ans = 0;

    FOR_(i, s, b) chmodadd(ans, dp[t][i]);

    PRINTLN(ans);

    return 0;
}
