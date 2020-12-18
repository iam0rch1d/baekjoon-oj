#include <cstring>
#include <iostream>

using namespace std;

#define MODULO 1000000007

long long dp[51][51][51][51];

long long memoize(int s, int a, int b, int c) {
    if (!s) return !a && !b && !c;

    auto &ret = dp[s][a][b][c];

    if (ret != -1) return ret;

    ret = 0;

    for (int i = 0; i < 7; i++) {
        int na = a - ("1010101"[i] - '0');
        int nb = b - ("0110011"[i] - '0');
        int nc = c - ("0001111"[i] - '0');

        if (na < 0 || nb < 0 || nc < 0) continue;

        ret = (ret + memoize(s - 1, na, nb, nc)) % MODULO;
    }

    return ret;
}

int main() {
    int s;
    int a;
    int b;
    int c;

    memset(dp, -1, sizeof(dp));

    cin >> s >> a >> b >> c;
    cout << memoize(s, a, b, c) << '\n';

    return 0;
}
