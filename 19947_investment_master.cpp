#include <iostream>

using namespace std;

using ll = long long;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

ll dp[11];

int main() {
    int y;

    cin >> dp[0] >> y;

    FOR_(i, 0, y) {
        if (i + 1 <= y) chmax(dp[i + 1], dp[i] + dp[i] / 20);

        if (i + 3 <= y) chmax(dp[i + 3], dp[i] + dp[i] / 5);

        if (i + 5 <= y) chmax(dp[i + 5], dp[i] + dp[i] * 7 / 20);
    }

    PRINTLN(dp[y]);

    return 0;
}
