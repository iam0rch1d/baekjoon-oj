#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    vvi a(n + 1, vi(n + 1, 0));
    vvi s(n + 1, vi(n + 1, 0));

    FOR_(i, 1, n) {
        FOR_(j, 1, n) {
            cin >> a[i][j];

            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    while (m--) {
        int y1;
        int x1;
        int y2;
        int x2;

        cin >> y1 >> x1 >> y2 >> x2;

        PRINTLN(s[y2][x2] - s[y1 - 1][x2] - s[y2][x1 - 1] + s[y1 - 1][x1 - 1]);
    }

    return 0;
}
