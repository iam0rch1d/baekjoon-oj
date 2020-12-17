#include <cstring>
#include <iostream>

using namespace std;

#define UNKNOWN -1

int chapters[500];
int dp[500][500];

template<typename T>
void chmin(T &m, T q) {
    m = min(m, q);
}

int memoize(int left, int right) {
    if (left == right) return 0;

    int &ret = dp[left][right];

    if (ret != UNKNOWN) return ret;

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

        memset(dp, UNKNOWN, sizeof(dp));

        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> chapters[i];
        }

        cout << memoize(0, k - 1) << '\n';
    }

    return 0;
}
