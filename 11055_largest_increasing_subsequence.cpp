#include <algorithm>
#include <iostream>

using namespace std;

int n;
int a[1000];
int maxSumCache[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        maxSumCache[i] = a[i];

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) maxSumCache[i] = max(maxSumCache[i], maxSumCache[j] + a[i]);
        }
    }

    cout << *max_element(maxSumCache, maxSumCache + n) << '\n';

    return 0;
}
