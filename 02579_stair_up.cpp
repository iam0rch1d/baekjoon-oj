#include <iostream>
#include <vector>

using namespace std;

int main() {
    int stairsSize;

    cin >> stairsSize;

    vector<int> stairs(stairsSize);
    vector<int> dp(stairsSize);

    for (int &stair : stairs) {
        cin >> stair;
    }

    dp[0] = stairs[0];

    if (stairs.size() == 1) {
        cout << dp[0] << '\n';

        return 0;
    }

    dp[1] = stairs[1] + stairs[0];

    if (stairs.size() == 2) {
        cout << dp[1] << '\n';

        return 0;
    }

    dp[2] = stairs[2] + max(stairs[1], stairs[0]);

    if (stairs.size() == 3) {
        cout << dp[2] << '\n';

        return 0;
    }

    for (int i = 3; i < stairsSize; i++) {
        dp[i] = stairs[i] + max(stairs[i - 1] + dp[i - 3], dp[i - 2]);
    }

    cout << dp[stairsSize - 1] << '\n';

    return 0;
}
