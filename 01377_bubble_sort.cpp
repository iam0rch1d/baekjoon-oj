#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int maxSortNo = 0;

    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;

        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        maxSortNo = max(maxSortNo, a[i].second - i);
    }

    cout << maxSortNo + 1 << '\n';

    return 0;
}
