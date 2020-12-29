#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

string add(string x, string y) {
    if (x.size() < y.size()) swap(x, y);

    int xSize = x.size();
    int ySize = y.size();

    x += '0';
    y += string(xSize - ySize + 1, '0');

    string ret(xSize + 1, '0');

    int carry = 0;

    FOR_(i, 0, xSize) {
        int temp = x[i] - '0' + y[i] - '0' + carry;

        ret[i] = temp % 10 + '0';
        carry = temp >= 10;
    }

    while (ret.back() == '0') {
        ret.pop_back();
    }

    return ret;
}

int main() {
    int n;
    int m;

    cin >> n >> m;

    vector<vector<string>> dp(n + 1, vector<string>(m + 1, "0"));

    FOR_(i, 0, n) dp[i][0] = "1";

    FOR_(i, 1, m) dp[i][i] = "1";

    FOR_(i, 2, n) FOR_(j, 1, m) dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j]);

    reverse(ALL(dp[n][m]));
    PRINTLN(dp[n][m]);

    return 0;
}
