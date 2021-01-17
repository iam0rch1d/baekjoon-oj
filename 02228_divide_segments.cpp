#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmax(T &m, T q) { if (m < q) { m = q; return true; } return false; }

int a[101];
int s[101];
int isVisited[101][51];
int dp[101][51];

int main() {
    int n;
    int m;

    cin >> n >> m;

    FOR_(i, 1, n) {
        cin >> a[i];

        s[i] = s[i - 1] + a[i];
    }

    FUN<int(int, int)> memoize = [&](int index, int segments) {
        if (segments == 0) return 0;
        else if (index <= 0) return -987654321;

        if (isVisited[index][segments]) return dp[index][segments];

        isVisited[index][segments] = true;

        int &ret = dp[index][segments];

        ret = memoize(index - 1, segments);

        FOR_(i, 1, index) chmax(ret, memoize(i - 2, segments - 1) + s[index] - s[i - 1]);

        return ret;
    };

    PRINTLN(memoize(n, m));

    return 0;
}
