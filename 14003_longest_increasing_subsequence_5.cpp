#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<long long> lis;
    unsigned long long lisLength;
    stack<long long> lisElements;

    cin >> n;

    vector<long long> a(n);
    vector<int> lisIndices(n);

    lis.push_back(-1000000001);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > lis.back()) {
            lis.push_back(a[i]);
            lisIndices[i] = lis.size() - 1;
        } else {
            auto toSwap = lower_bound(lis.begin(), lis.end(), a[i]);
            int toSwapLisIndex;

            *toSwap = a[i];

            toSwapLisIndex = toSwap - lis.begin();
            lisIndices[i] = toSwapLisIndex;
        }
    }

    lisLength = lis.size() - 1;

    cout << lisLength << '\n';

    for (int i = n - 1; i >= 0; i--) {
        if (!lisLength) break;

        if (lisIndices[i] == lisLength) {
            lisElements.push(a[i]);

            lisLength--;
        }
    }

    while (!lisElements.empty()) {
        cout << lisElements.top() << ' ';

        lisElements.pop();
    }

    cout << '\n';

    return 0;
}
