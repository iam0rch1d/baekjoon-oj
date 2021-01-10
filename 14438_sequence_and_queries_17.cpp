#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define INF 1000000001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vi a(n + 1);

    FOR_(i, 1, n) cin >> a[i];

    int height = (int) ceil(log2(n)) + 1;
    vi segtree(1 << height, INF);

    function<int(int, int, int)> init = [&](int node, int left, int right) {
        if (left == right) return segtree[node] = a[left];

        int mid = (left + right) / 2;

        return segtree[node] = min(init(node * 2, left, mid), init(node * 2 + 1, mid + 1, right));
    };

    init(1, 1, n);

    function<void(int, int, int, int, int)> q1 = [&](int node, int left, int right, int index, int value) {
        // Update
        if (index < left || index > right) return;

        if (left == right) {
            segtree[node] = value;

            return;
        }

        int mid = (left + right) / 2;

        q1(node * 2, left, mid, index, value);
        q1(node * 2 + 1, mid + 1, right, index, value);

        segtree[node] = min(segtree[node * 2], segtree[node * 2 + 1]);
    };

    function<int(int, int, int, int, int)> q2 = [&](int node, int left, int right, int x, int y) {
        // Get minimum value
        if (x > right || y < left) return INF;
        else if (x <= left && y >= right) return segtree[node];

        int mid = (left + right) / 2;
        int leftChild = q2(node * 2, left, mid, x, y);
        int rightChild = q2(node * 2 + 1, mid + 1, right, x, y);

        return min(leftChild, rightChild);
    };

    int m;

    cin >> m;

    while (m--) {
        int q;

        cin >> q;

        if (q == 1) {
            int i;
            int v;

            cin >> i >> v;

            q1(1, 1, n, i, v);
        } else {
            int i;
            int j;

            cin >> i >> j;

            PRINTLN(q2(1, 1, n, i, j));
        }
    }

    return 0;
}
