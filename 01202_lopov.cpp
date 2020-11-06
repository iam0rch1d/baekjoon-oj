#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;
    long long totalValue = 0;

    cin >> n >> k;

    vector<pair<long long, long long>> gems(n);
    multiset<long long> capacities;

    for (auto &gem : gems) {
        cin >> gem.first >> gem.second;
    }

    for (int i = 0; i < k; i++) {
        long long capacity;

        cin >> capacity;

        capacities.insert(capacity);
    }

    sort(gems.begin(), gems.end(), [](auto i, auto j) { return i.second > j.second; });

    for (int i = 0; i < n; i++) {
        auto toPick = capacities.lower_bound(gems[i].first);

        if (toPick != capacities.end()) {
            totalValue += gems[i].second;

            capacities.erase(toPick);
        }
    }

    cout << totalValue << '\n';

    return 0;
}
