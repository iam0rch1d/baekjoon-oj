#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
void chmin(T &m, T q) { m = min(m, q); }

int n;
int m;
int nameLengths[1000];
int dp[1000][1002];

int memoize(int name, int column) {
    if (name == n) return 0;

    int &ret = dp[name][column];

    if (ret != -1) return ret;

    ret = memoize(name + 1, nameLengths[name] + 1) + (m - (column - 1)) * (m + (column - 1));

    if (column + nameLengths[name] <= m) chmin(ret, memoize(name + 1, column + nameLengths[name] + 1));

    return ret;
}

int main() {
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
        cin >> nameLengths[i];
    }

    cout << memoize(0, 0) << '\n';

    return 0;
}
