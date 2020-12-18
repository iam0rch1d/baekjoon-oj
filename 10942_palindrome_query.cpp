#include <cstring>
#include <iostream>

using namespace std;

int a[2000];
int dp[2000][2000];

int memoize(int left, int right) {
    if (left >= right) return 1;

    int &ret = dp[left][right];

    if (ret != -1) return ret;

    return ret = memoize(left + 1, right - 1) * (a[left] == a[right]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    while (m--) {
        int s;
        int e;

        cin >> s >> e;

        cout << memoize(s - 1, e - 1) << '\n';
    }

    return 0;
}
