#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

int dist[100001];
int dp[100001];

int main() {
    int n;
    int k;

    cin >> n >> k;

    RESET(dist, -1);

    dist[n] = 0;
    dp[n] = 1;

    queue<int> bfsVertices;

    bfsVertices.push(n);

    while (!bfsVertices.empty()) {
        int x = bfsVertices.front();

        bfsVertices.pop();

        for (int y : {x - 1, x + 1, 2 * x}) {
            if (y < 0 || y > 100000) continue;

            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                dp[y] = dp[x];

                bfsVertices.push(y);
            } else if (dist[y] == dist[x] + 1) dp[y] += dp[x];
        }
    }

    PRINTLN(dist[k]);
    PRINTLN(dp[k]);

    return 0;
}
