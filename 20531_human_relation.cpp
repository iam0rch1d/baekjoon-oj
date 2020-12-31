#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    vector<int> parents(n, -1);

    auto ufFind = [&](int x) {
        while (parents[x] >= 0) {
            if (parents[parents[x]] >= 0) parents[x] = parents[parents[x]];

            x = parents[x];
        }

        return x;
    };

    auto ufUnion = [&](int x, int y) {
        x = ufFind(x);
        y = ufFind(y);

        if (x == y) return false;

        if (parents[x] > parents[y]) swap(x, y);

        parents[x] += parents[y];
        parents[y] = x;

        return true;
    };

    vvl dp(n + 1, vl(n + 1, 0));

    dp[1][1] = 1;

    FOR_(i, 2, n) {
        dp[i][1] = 1;

        FOR_(j, 2, i) dp[i][j] = (dp[i - 1][j - 1] + j * dp[i - 1][j] % MODULO) % MODULO;
    }

    dp[1][0] = 1;

    FOR_(i, 2, n) FOR_(j, 1, i) dp[i][0] = (dp[i][0] + dp[i][j]) % MODULO;

    int unionCount = n;

    while (m--) {
        int x;
        int y;

        cin >> x >> y;

        --x;
        --y;

        if (ufUnion(x, y)) unionCount--;

        PRINTLN(dp[unionCount][0]);
    }

    return 0;
}
