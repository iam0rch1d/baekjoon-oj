#include <iostream>
#include <vector>

using namespace std;

bool dp[101];

int main() {
    string s;
    int n;
    int sSize;

    cin >> s >> n;

    sSize = s.size();

    vector<string> a(n);

    for (auto &ai : a) {
        cin >> ai;
    }

    dp[0] = true;

    for (int i = 0; i < sSize; i++) {
        for (int j = 0; j < n; j++) {
            int ajSize = a[j].size();

            if (a[j] == s.substr(i, ajSize) && dp[i]) dp[i + ajSize] = dp[i];
        }
    }

    cout << dp[sSize] << '\n';

    return 0;
}
