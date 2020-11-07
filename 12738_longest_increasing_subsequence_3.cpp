#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<long long> lis;  // 'LIS' refers to 'Longest Increasing Subsequence'

    cin >> n;

    lis.push_back(-1000000001);

    for (long long i = 0; i < n; i++) {
        int element;

        cin >> element;

        if (lis.back() < element) lis.push_back(element);
        else {
            auto toSwap = lower_bound(lis.begin(), lis.end(), element);

            *toSwap = element;
        }
    }

    cout << lis.size() - 1 << '\n';

    return 0;
}
