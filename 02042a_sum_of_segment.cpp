#include <iostream>

using namespace std;

using ll = long long;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define MAX_SIZE (1 << 21)

ll leafBase = 1;
ll a[1000001];
ll segtree[MAX_SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    while (leafBase <= n) leafBase *= 2;

    leafBase--;

    auto update = [&](int x, ll diff) {
        x += leafBase;

        while (x) {
            segtree[x] += diff;
            x /= 2;
        }
    };

    auto query = [&](int left, int right) {
        left += leafBase;
        right += leafBase;

        ll ret = 0;

        while (left < right) {
            if (left % 2 == 0) left /= 2;
            else {
                ret += segtree[left];
                left = (left + 1) / 2;
            }

            if (right % 2 == 1) right /= 2;
            else {
                ret += segtree[right];
                right = (right - 1) / 2;
            }
        }

        if (left == right) ret += segtree[left];

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

            update(i, value - a[i]);

            a[i] = value;
        } else {
            int left;
            int right;

            cin >> left >> right;

            PRINTLN(query(left, right));
        }
    }

    return 0;
}
