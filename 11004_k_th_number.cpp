#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;

    cin >> n >> k;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    sort(a.begin(), a.end());

    cout << a[k - 1] << '\n';

    return 0;
}
