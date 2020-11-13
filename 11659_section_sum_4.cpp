#include <iostream>

using namespace std;

int a[100001];
int s[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        s[i] = s[i - 1] + a[i];
    }

    while (m--) {
        int i;
        int j;

        cin >> i >> j;
        cout << s[j] - s[i - 1] << '\n';
    }

    return 0;
}
