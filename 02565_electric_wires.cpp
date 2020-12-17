#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int connectionsSize;
    int connections[501];
    int fromPole;
    int toPole;
    int maxFromPole = 0;
    int dp[501];

    cin >> connectionsSize;

    memset(connections, 0, sizeof(connections));

    for (int i = 0; i < connectionsSize; i++) {
        cin >> fromPole >> toPole;

        connections[fromPole] = toPole;
        maxFromPole = max(maxFromPole, fromPole);
    }

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= maxFromPole; i++) {
        for (int j = 0; j < i; j++) {
            if (connections[j] < connections[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
    }

    cout << connectionsSize - *max_element(dp, dp + maxFromPole + 1) << '\n';

    return 0;
}
