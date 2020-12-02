#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> fronts;
    vector<int> backs;
    long long tupleCount = 0;

    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fronts.push_back(a[i] + b[j]);
            backs.push_back(c[i] + d[j]);
        }
    }

    sort(backs.begin(), backs.end());

    for (int front : fronts) {
        auto backEqualRange = equal_range(backs.begin(), backs.end(), -front);

        tupleCount += backEqualRange.second - backEqualRange.first;
    }

    cout << tupleCount << '\n';

    return 0;
}
