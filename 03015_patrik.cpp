#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    stack<pair<int, long long>> heights;  // .first = <height>, .second = <number of people with same height>
    long long visibleCount = 0;

    cin >> n;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    for (int i = 0; i < n; i++) {
        int sameHeightCount = 1;

        while (!heights.empty() && heights.top().first <= a[i]) {
            visibleCount += heights.top().second;

            if (heights.top().first == a[i]) sameHeightCount += heights.top().second;

            heights.pop();
        }

        visibleCount += !heights.empty();

        heights.push({a[i], sameHeightCount});
    }

    cout << visibleCount << '\n';

    return 0;
}
