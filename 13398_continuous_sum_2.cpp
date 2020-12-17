#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    int a[100002];
    int aSum = 0;

    int dpTo[100002];
    int dpFrom[100002];
    int dpWithout[100002];

    cin >> n;

    dpTo[0] = -1001;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        aSum += a[i];
        dpTo[i] = a[i] + max(dpTo[i - 1], 0);
    }

    dpFrom[n + 1] = -1001;

    for (int i = n; i >= 0; i--) {
        dpFrom[i] = a[i] + max(dpFrom[i + 1], 0);
    }

    for (int i = 1; i <= n; i++) {
        dpWithout[i] = max({dpTo[i - 1] + dpFrom[i + 1], dpTo[i - 1], dpFrom[i + 1]});
    }

    cout << max(aSum, *max_element(dpWithout + 1, dpWithout + n + 1)) << '\n';

    return 0;
}
