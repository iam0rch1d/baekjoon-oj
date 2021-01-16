#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

template<typename T>
bool chmin(T &m, T q) { if (m > q) { m = q; return true; } return false; }

int a[100];
int b[100];
int dp[100][10][10];
int costs[] = {0, 1, 1, 1, 2, 2, 2, 1, 1, 1};

int main() {
    int n;

    cin >> n;

    string aString;
    string bString;

    cin >> aString >> bString;

    REP(i, n) {
        a[i] = aString[i] - '0';
        b[i] = bString[i] - '0';
    }

    FUN<int(int, int, int)> memoize = [&](int disk, int turns, int nextTurns) {
        if (disk == n) return 0;

        int &ret = dp[disk][turns][nextTurns];

        if (ret != -1) return ret;

        ret = 987654321;

        REP(three, 10) {
            REP(two, 10) {
                int currentDisk = (a[disk] + turns + two + three) % 10;
                int one = (b[disk] - currentDisk + 10) % 10;

                chmin(ret, costs[one] + costs[two] + costs[three]
                           + memoize(disk + 1, (nextTurns + two + three) % 10, three));
            }
        }

        return ret;
    };

    RESET(dp, -1);
    PRINTLN(memoize(0, 0, 0));

    return 0;
}
