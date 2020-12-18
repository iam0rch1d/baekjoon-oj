#include <cstring>
#include <iostream>

using namespace std;

#define MODULO 1000000007

int n;
int m;
int p;
long long dp[101][101];

long long memoize(int playedSongs, int stagedSongs) {
    if (playedSongs == p) return stagedSongs == n;

    auto &ret = dp[playedSongs][stagedSongs];

    if (ret != -1) return ret;

    int unstagedSongs = n - stagedSongs;

    ret = 0;

    if (unstagedSongs > 0) ret = ret + memoize(playedSongs + 1, stagedSongs + 1) * unstagedSongs % MODULO;

    if (stagedSongs - m > 0) ret = (ret + memoize(playedSongs + 1, stagedSongs) * (stagedSongs - m) % MODULO) % MODULO;

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> p;
    cout << memoize(0, 0) << '\n';

    return 0;
}
