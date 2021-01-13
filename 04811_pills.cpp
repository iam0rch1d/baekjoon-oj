#include <functional>
#include <iostream>

using namespace std;

using ll = long long;

#define FUN function
#define PRINTLN(x) cout << (x) << '\n'

ll dp[31][31];

int main() {
    FUN<ll(int, int)> memoize = [&](int w, int h) -> ll {
        if (!w && !h) return 1;

        ll &ret = dp[w][h];

        if (ret) return ret;

        ret = 0;

        if (w > 0) ret += memoize(w - 1, h + 1);

        if (h > 0) ret += memoize(w, h - 1);

        return ret;
    };

    while (true) {
        int n;

        cin >> n;

        if (!n) return 0;

        PRINTLN(memoize(n, 0));
    }
}
