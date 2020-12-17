#include <cstring>
#include <iostream>

using namespace std;

#define MAX_N 31

int n;
int k;
bool dp[MAX_N][MAX_N][MAX_N][(MAX_N - 1) * (MAX_N - 2) / 2 + 1];
char ans[MAX_N];

bool memoize(int length, int a, int b, int pairs) {
    if (length == n) return pairs == k;

    bool &ret = dp[length][a][b][pairs];

    if (ret) return false;

    ret = true;
    ans[length] = 'A';

    if (memoize(length + 1, a + 1, b, pairs)) return true;

    ans[length] = 'B';

    if (memoize(length + 1, a, b + 1, pairs + a)) return true;

    ans[length] = 'C';

    if (memoize(length + 1, a, b, pairs + a + b)) return true;

    return false;
}

int main() {
    cin >> n >> k;
    cout << (memoize(0, 0, 0, 0) ? ans : "-1") << '\n';

    return 0;
}
