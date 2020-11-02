#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    int a[100000];
    int maxCsCache[100000];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        maxCsCache[i] = a[i] + (i == 0 ? 0 : max(maxCsCache[i - 1], 0));
    }

    cout << *max_element(maxCsCache, maxCsCache + n) << '\n';

    return 0;
}
