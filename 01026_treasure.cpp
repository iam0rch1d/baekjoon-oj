#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int minS = 0;

    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int &ai : a) {
        cin >> ai;
    }

    for (int &bi : b) {
        cin >> bi;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    for (int i = 0; i < n; i++) {
        minS += a[i] * b[i];
    }

    cout << minS << '\n';

    return 0;
}
