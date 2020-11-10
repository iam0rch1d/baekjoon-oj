#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n;

    vector<int> cards(n);

    for (int &card : cards) {
        cin >> card;
    }

    sort(cards.begin(), cards.end());

    cin >> m;

    while (m--) {
        int target;

        cin >> target;

        auto targetRange = equal_range(cards.begin(), cards.end(), target);

        cout << targetRange.second - targetRange.first << ' ';
    }

    cout << '\n';

    return 0;
}
