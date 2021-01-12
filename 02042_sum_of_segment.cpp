#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    vl a(n + 1);

    FOR_(i, 1, n) cin >> a[i];

    int height = (int) ceil(log2(n)) + 1;
    vl segtree(1 << height, 0);

    function<ll(int, int, int)> init = [&](int node, int left, int right) {
        if (left == right) return segtree[node] = a[left];

        int mid = (left + right) / 2;

        return segtree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
    };

    init(1, 1, n);

    function<void(int, int, int, int, ll)> q1 = [&](int node, int left, int right, int index, ll diff) {
        // Update
        if (index < left || index > right) return;

        segtree[node] += diff;

        if (left != right) {
            int mid = (left + right) / 2;

            q1(node * 2, left, mid, index, diff);
            q1(node * 2 + 1, mid + 1, right, index, diff);
        }
    };

    function<ll(int, int, int, int, ll)> q2 = [&](int node, int left, int right, int x, int y) -> ll {
        // Get sum of segment
        if (x > right || y < left) return 0;
        else if (x <= left && y >= right) return segtree[node];

        int mid = (left + right) / 2;

        return q2(node * 2, left, mid, x, y) + q2(node * 2 + 1, mid + 1, right, x, y);
    };

    m += k;

    while (m--) {
        int q;

        cin >> q;

        if (q == 1) {
            int i;
            ll v;

            cin >> i >> v;

            q1(1, 1, n, i, v - a[i]);

            a[i] = v;
        } else {
            int i;
            int j;

            cin >> i >> j;

            PRINTLN(q2(1, 1, n, i, j));
        }
    }

    return 0;
}
