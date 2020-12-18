#include <cstring>
#include <iostream>

using namespace std;

#define MODULO 100000LL

int n;
string s;
long long dp[200][200];
const char opens[]{"({["};
const char closes[]{")}]"};

long long memoize(int left, int right) {
    if (left > right) return 1;

    auto &ret = dp[left][right];

    if (ret != -1) return ret;

    ret = 0;

    for (int close = left + 1; close <= right; close += 2) {
        for (int i = 0; i < 3; i++) {
            if ((s[left] == '?' || s[left] == opens[i]) && (s[close] == '?' || s[close] == closes[i])) {
                ret += memoize(left + 1, close - 1) * memoize(close + 1, right);

                if (ret >= MODULO) ret = ret % MODULO + MODULO;
            }
        }
    }

    return ret;
}

int main() {
    long long ans;

    memset(dp, -1, sizeof(dp));

    cin >> n >> s;

    ans = memoize(0, n - 1);

    if (ans >= MODULO) printf("%05lld\n", ans % MODULO);
    else printf("%lld\n", ans);

    return 0;
}
