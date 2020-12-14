#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

int t[1500000];
long long p[1500000];
long long maxTotalPayCache[1500051];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 0; i < n; i++) {
        chmax(maxTotalPayCache[i + t[i]], maxTotalPayCache[i] + p[i]);
        chmax(maxTotalPayCache[i + 1], maxTotalPayCache[i]);
    }

    cout << maxTotalPayCache[n] << '\n';

    return 0;
}
