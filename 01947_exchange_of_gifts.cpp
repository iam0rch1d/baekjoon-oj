#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

using ll = long long;

#define FUN function
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000000000

template<typename T>
void chmodadd(T &x, T q) { x = (x + q) % MODULO; }

ll dp[1000001];

int main() {
    int n;

    cin >> n;

    FUN<ll(int)> memoize = [&](int n) -> ll {
        if (n <= 1) return !n;

        ll &ret = dp[n];

        if (ret != -1) return ret;

        ret = 0;

        chmodadd(ret, memoize(n - 2) * (ll) (n - 1) % MODULO);
        chmodadd(ret, memoize(n - 1) * (ll) (n - 1) % MODULO);

        return ret;
    };

    RESET(dp, -1);
    PRINTLN(memoize(n));

    return 0;
}
