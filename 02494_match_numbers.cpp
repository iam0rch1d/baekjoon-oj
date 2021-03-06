#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

#define FUN function
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

int a[10000];
int b[10000];
int dp[10000][10];
int dpDirection[10000][10];
int dpCost[10000][10];
int dpNextTurns[10000][10];

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

    FUN<int(int, int)> memoize = [&](int screw, int turns) {
        if (screw == n) return 0;

        int &ret = dp[screw][turns];

        if (ret != -1) return ret;

        int currentScrew = (a[screw] + turns) % 10;
        int leftCost = (b[screw] - currentScrew + 10) % 10;
        int rightCost = 10 - leftCost;
        int leftDist = memoize(screw + 1, (turns + leftCost) % 10);
        int rightDist = memoize(screw + 1, turns);

        if (leftCost + leftDist < rightCost + rightDist) {
            ret = leftCost + leftDist;
            dpDirection[screw][turns] = 1;
            dpCost[screw][turns] = leftCost;
            dpNextTurns[screw][turns] = (turns + leftCost) % 10;
        } else {
            ret = rightCost + rightDist;
            dpDirection[screw][turns] = -1;
            dpCost[screw][turns] = rightCost;
            dpNextTurns[screw][turns] = turns;
        }

        return ret;
    };

    FUN<void(int, int)> traceforward = [&](int screw, int turns) {
        if (screw == n) return;

        if (!dpCost[screw][turns]) traceforward(screw + 1, turns);
        else {
            PRINT(screw + 1);
            PRINTLN(dpDirection[screw][turns] * dpCost[screw][turns]);

            traceforward(screw + 1, dpNextTurns[screw][turns]);
        }
    };

    RESET(dp, -1);
    PRINTLN(memoize(0, 0));
    traceforward(0, 0);

    return 0;
}
