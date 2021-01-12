#include <iostream>

using namespace std;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int a[1025][1025];
int fenwicktree[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    auto update = [&](int y, int x, int diff) {
        for (int i = y; i <= n; i += i & -i) {
            for (int j = x; j <= n; j += j & -j) {
                fenwicktree[i][j] += diff;
            }
        }
    };

    auto query = [&](int y, int x) {
        int ret = 0;

        for (int i = y; i; i -= i & -i) {
            for (int j = x; j; j -= j & -j) {
                ret += fenwicktree[i][j];
            }
        }

        return ret;
    };

    FOR_(i, 1, n) {
        FOR_(j, 1, n) {
            cin >> a[i][j];

            update(i, j, a[i][j]);
        }
    }

    while (m--) {
        int q;

        cin >> q;

        if (q) {
            int y1;
            int x1;
            int y2;
            int x2;

            cin >> y1 >> x1 >> y2 >> x2;

            PRINTLN(query(y2, x2) - query(y1 - 1, x2) - query(y2, x1 - 1) + query(y1 - 1, x1 - 1));
        } else {
            int y;
            int x;
            int c;

            cin >> y >> x >> c;

            update(y, x, c - a[y][x]);

            a[y][x] = c;
        }
    }

    return 0;
}
