#include <iostream>

using namespace std;

#define MAX_SIZE 32

int map[MAX_SIZE][MAX_SIZE];
long long dp[MAX_SIZE][MAX_SIZE][3];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        if (map[0][i]) break;

        dp[0][i][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 2; j < n; j++) {
            if (!map[i][j]) {
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
                dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];

                if (!map[i - 1][j] && !map[i][j - 1]) {
                    dp[i][j][1] = dp[i - 1][j - 1][0]
                                  + dp[i - 1][j - 1][1]
                                  + dp[i - 1][j - 1][2];
                }
            }
        }
    }

    cout << dp[n - 1][n - 1][0]
            + dp[n - 1][n - 1][1]
            + dp[n - 1][n - 1][2] << '\n';

    return 0;
}
