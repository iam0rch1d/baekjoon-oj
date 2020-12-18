#include <cstring>
#include <iostream>

using namespace std;

#define MODULO 9901

int dp[100001];

int memoize(int size) {
    if (size == 0) return 1;
    else if (size == 1) return 3;

    int &ret = dp[size];

    if (ret != -1) return ret;

    return ret = (2 * memoize(size - 1) + memoize(size - 2)) % MODULO;
}

int main() {
    int size;

    memset(dp, -1, sizeof(dp));

    cin >> size;
    cout << memoize(size) << '\n';

    return 0;
}
