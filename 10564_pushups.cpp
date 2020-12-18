#include <cstring>
#include <iostream>

using namespace std;

int n;
int m;
int s[10];
bool dp[5001][5001];

void memoize(int pushups, int score) {
    if (pushups > n) return;

    bool &currentState = dp[pushups][score];

    if (currentState) return;

    currentState = true;

    for (int i = 0; i < m; i++) {
        memoize(pushups + score + s[i], score + s[i]);
    }
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        int ans = -1;

        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> s[i];
        }

        memoize(0, 0);

        for (int i = 1; i <= n; i++) {
            if (dp[n][i]) ans = i;
        }

        cout << ans << '\n';

        memset(dp, false, sizeof(dp));
    }

    return 0;
}
