#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long t;
    int n;
    int m;
    int frontsSize = 0;
    vector<long long> fronts;
    long long tCount = 0;

    cin >> t >> n;

    vector<long long> a(n);

    for (auto &ai : a) {
        cin >> ai;
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            frontsSize++;
            sum += a[j];

            fronts.push_back(sum);
        }
    }

    cin >> m;

    vector<long long> b(m);
    vector<long long> backs;

    for (auto &bi : b) {
        cin >> bi;
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;

        for (int j = i; j < m; j++) {
            sum += b[j];

            backs.push_back(sum);
        }
    }

    sort(fronts.begin(), fronts.end());
    sort(backs.begin(), backs.end());

    for (int i = 0; i < frontsSize; i++) {
        auto backEqualRange = equal_range(backs.begin(), backs.end(), t - fronts[i]);

        tCount += backEqualRange.second - backEqualRange.first;
    }

    cout << tCount << '\n';

    return 0;
}
