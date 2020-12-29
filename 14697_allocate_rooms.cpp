#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int a;
    int b;
    int c;
    int n;

    cin >> a >> b >> c >> n;

    vi dp(n + 1, -1);
    function<int(int)> memoize = [&](int n) {
        if (!n) return 1;
        else if (n < 0) return 0;

        int &ret = dp[n];

        if (ret != -1) return ret;

        return ret = memoize(n - a) || memoize(n - b) || memoize(n - c);
    };

    PRINTLN(memoize(n));

    return 0;
}
