#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

#define INF 999999

int main() {
    int n;

    cin >> n;

    vi dp(n + 1, INF);

    dp[1] = 0;

    function<int(int)> memoize = [&](int n) {
        int &ret = dp[n];

        if (ret != INF) return ret;

        return ret = min({n % 3 ? INF : memoize(n / 3), n % 2 ? INF : memoize(n / 2), memoize(n - 1)}) + 1;
    };

    PRINTLN(memoize(n));
    PRINT(n);

    while (n != 1) {
        if (n % 3 == 0 && dp[n / 3] == dp[n] - 1) {
            n /= 3;

            PRINT(n);

            continue;
        }

        if (n % 2 == 0 && dp[n / 2] == dp[n] - 1) {
            n /= 2;

            PRINT(n);

            continue;
        }

        PRINT(--n);
    }

    PRINTLN("");

    return 0;
}
