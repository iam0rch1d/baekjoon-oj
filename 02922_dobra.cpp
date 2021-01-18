#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

using ll = long long;

#define FUN function
#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define RESET(arr, x) memset(arr, x, sizeof(arr))
#define PRINTLN(x) cout << (x) << '\n'

int typeOf(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ? 1 : 2;
}

ll typeSizes[]{0, 5, 20};
ll dp[100][3][3][2];  // (<index>, <back>, <twice back>, <has 'L'>)

int main() {
    string s;

    cin >> s;

    int n = s.size();

    FUN<ll(int, int, int, int)> memoize = [&](int index, int p1, int p2, int hasL) -> ll {
        if (index == n) return hasL;

        ll &ret = dp[index][p1][p2][hasL];

        if (ret != -1) return ret;

        ret = 0;

        if (s[index] != '_') {
            if (typeOf(s[index]) == p1 && p1 == p2) return 0;

            return ret = memoize(index + 1, typeOf(s[index]), p1, hasL | (s[index] == 'L'));
        }

        FOR_(type, 1, 2) if (type != p1 || p1 != p2) ret += typeSizes[type] * memoize(index + 1, type, p1, hasL);

        if (p1 != 2 || p1 != p2) ret += memoize(index + 1, 2, p1, 1);  // 'L' is consonant(2)

        return ret;
    };

    RESET(dp, -1);
    PRINTLN(memoize(0, 0, 0, 0));

    return 0;
}
