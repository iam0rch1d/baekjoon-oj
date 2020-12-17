#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1
#define MODULO 10007

int dp[1001];

int memoize(int width) {
    if (width == 1) return 1;
    else if (width == 2) return 3;

    int &ret = dp[width];

    if (ret != UNKNOWN) return ret;

    return ret = (memoize(width - 1) + 2 * memoize(width - 2)) % MODULO;
}

int main() {
    int width;

    memset(dp, UNKNOWN, sizeof(dp));

    cin >> width;
    cout << memoize(width) << '\n';

    return 0;
}
