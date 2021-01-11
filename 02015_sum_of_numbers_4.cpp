#include <iostream>
#include <map>
#include <vector>

using namespace std;

using ll = long long;
using vi = vector<int>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;

    cin >> n >> k;

    vi a(n + 1, 0);
    vi s(n + 1, 0);
    map<int, int> counts;
    ll ans = 0;

    counts[0] = 1;

    FOR_(i, 1, n) {
        cin >> a[i];

        s[i] = s[i - 1] + a[i];
        ans += counts[s[i] - k];
        counts[s[i]]++;
    }

    PRINTLN(ans);

    return 0;
}
