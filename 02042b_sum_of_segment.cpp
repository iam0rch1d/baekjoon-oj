#include <iostream>

using namespace std;

using ll = long long;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define MAX_SIZE (1 << 21)

ll a[1000001];
ll fenwicktree[MAX_SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    auto update = [&](int x, ll diff) {
        while (x < MAX_SIZE) {
            fenwicktree[x] += diff;
            x += x & -x;
        }
    };

    auto query = [&](int x) {
        ll ret = 0;

        while (x) {
            ret += fenwicktree[x];
            x -= x & -x;
        }

        return ret;
    };

    FOR_(i, 1, n) {
        cin >> a[i];

        update(i, a[i]);
    }

    m += k;

    while (m--) {
        int q;

        cin >> q;

        if (q == 1) {
            int i;
            ll value;

            cin >> i >> value;

            ll diff = value - a[i];

            a[i] = value;

            update(i, diff);
        } else {
            int left;
            int right;

            cin >> left >> right;

            PRINTLN(query(right) - query(left - 1));
        }
    }

    return 0;
}
