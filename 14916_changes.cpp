#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define PRINTLN(x) cout << (x) << '\n'

#define INF 99999

int main() {
    int n;

    cin >> n;

    vi dp(n + 1, INF);
    function<int(int)> memoize = [&](int n) {
        if (!n) return 0;
        else if (n == 1 || n == 3 || n < 0) return INF;

        int &ret = dp[n];

        if (ret != INF) return ret;

        return ret = min(memoize(n - 2), memoize(n - 5)) + 1;
    };

    int ans = memoize(n);

    PRINTLN(ans == INF ? -1 : ans);

    return 0;
}
