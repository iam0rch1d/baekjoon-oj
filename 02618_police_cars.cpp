#include <iostream>
#include <stack>
#include <vector>

using namespace std;

using pii = pair<int, int>;
using vpii = vector<pii>;

#define F first
#define S second
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

template<typename T>
T manhattan(pair<T, T> a, pair<T, T> b) { return abs(b.F - a.F) + abs(b.S - a.S); }

#define INF 987654321

int dist[1003][1003];
int dp[1003][1003];
int dpBack[1003][1003];

int main() {
    int n;
    int w;

    cin >> n >> w;

    vpii events(w + 3);

    events[1] = {1, 1};
    events[2] = {n, n};

    FOR_(i, 3, w + 2) cin >> events[i].F >> events[i].S;

    FOR_(i, 1, w + 2) {
        FOR_(j, i, w + 2) {
            dist[i][j] = manhattan(events[i], events[j]);
            dist[j][i] = dist[i][j];
            dp[i][j] = INF;
            dp[j][i] = INF;
        }
    }

    dp[1][2] = 0;

    FOR_(i, 3, w + 2) {
        FOR(j, 1, i - 1) {
            if (j != 2) {
                if (chmin(dp[i][i - 1], dp[j][i - 1] + dist[j][i])) dpBack[i][i - 1] = j;

                dp[j][i] = dp[j][i - 1] + dist[i - 1][i];
                dpBack[j][i] = i - 1;
            }

            if (j >= 2) {
                if (chmin(dp[i - 1][i],  dp[i - 1][j] + dist[j][i])) dpBack[i - 1][i] = j;

                dp[i][j] = dp[i - 1][j] + dist[i - 1][i];
                dpBack[i][j] = i - 1;
            }
        }
    }

    int ans = INF;
    int police1;
    int police2;

    for (int i = 1; i <= w + 2; i++) {
        if (chmin(ans, dp[w + 2][i])) {
            police1 = w + 2;
            police2 = i;
        }

        if (chmin(ans, dp[i][w + 2])) {
            police1 = i;
            police2 = w + 2;
        }
    }

    stack<int> traceback;

    REP(i, w) {
        int back = dpBack[police1][police2];

        if (police1 > police2) {
            traceback.push(1);

            police1 = back;
        } else {
            traceback.push(2);

            police2 = back;
        }
    }

    PRINTLN(ans);

    while (!traceback.empty()) {
        PRINTLN(traceback.top());

        traceback.pop();
    }

    return 0;
}
