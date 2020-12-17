#include <iostream>

using namespace std;

int dpLis[1000];
int dpLds[1000];

int main() {
    int n;
    int a[1000];
    int ans = 1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) dpLis[i] = max(dpLis[i], dpLis[j] + 1);
        }
    }

    for (int i = n - 2; i > 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[i] > a[j]) dpLds[i] = max(dpLds[i], dpLds[j] + 1);
        }

        ans = max(ans, dpLis[i] + dpLds[i] + 1);
    }

    cout << ans << '\n';

    return 0;
}
