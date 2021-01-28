#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define IFOR(i, x, y) for (int i = (y) - 1; i >= (x); i--)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

vi dp[10001];

vi operator+(vi &a, vi &b) {
    if (a.size() < b.size()) return operator+(b, a);

    int aSize = a.size();
    int bSize = b.size();

    vi ret(aSize, 0);
    int carry = 0;

    REP(i, aSize) {
        if (i < bSize) ret[i] += b[i];

        ret[i] += a[i] + carry;
        carry = ret[i] / 10;
        ret[i] %= 10;
    }

    if (carry != 0) ret.push_back(carry);

    return ret;
}

int main() {
    dp[0] = {1};
    dp[1] = {1};
    dp[2] = {3};

    FOR_(i, 3, 10000) dp[i] = dp[i - 1] + dp[i - 2];

    int n;

    while (cin >> n) {
        int ansSize = dp[n].size();

        IFOR(i, 0, ansSize) cout << dp[n][i];

        PRINTLN("");
    }

    return 0;
}
