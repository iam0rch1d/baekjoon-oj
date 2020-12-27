#include <cstring>
#include <iostream>

using namespace std;

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

int chapters[500];
int dp[500][500];

int memoize(int left, int right) {
    if (left == right) return 0;

    int &ret = dp[left][right];

    if (ret != -1) return ret;

    int chapterSum = 0;

    for (int i = left; i <= right; i++) {
        chapterSum += chapters[i];
    }

    ret = 987654321;

    for (int i = left; i <= right; i++) {
        chmin(ret, memoize(left, i) + memoize(i + 1, right));
    }

    return ret += chapterSum;
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int k;

        memset(dp, -1, sizeof(dp));

        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> chapters[i];
        }

        cout << memoize(0, k - 1) << '\n';
    }

    return 0;
}
