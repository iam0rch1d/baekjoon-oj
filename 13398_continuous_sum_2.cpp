#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    int a[100002];
    int aSum = 0;

    // 'CS' refers to 'Continuous Sum'
    int maxCsCacheTo[100002];
    int maxCsCacheFrom[100002];
    int maxCsCacheWithout[100002];

    cin >> n;

    maxCsCacheTo[0] = -1001;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        aSum += a[i];
        maxCsCacheTo[i] = a[i] + max(maxCsCacheTo[i - 1], 0);
    }

    maxCsCacheFrom[n + 1] = -1001;

    for (int i = n; i >= 0; i--) {
        maxCsCacheFrom[i] = a[i] + max(maxCsCacheFrom[i + 1], 0);
    }

    for (int i = 1; i <= n; i++) {
        maxCsCacheWithout[i] = max({maxCsCacheTo[i - 1] + maxCsCacheFrom[i + 1],
                               maxCsCacheTo[i - 1],
                               maxCsCacheFrom[i + 1]});
    }

    cout << max(aSum, *max_element(maxCsCacheWithout + 1, maxCsCacheWithout + n + 1)) << '\n';

    return 0;
}
