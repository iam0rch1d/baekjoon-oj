#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int maxTotalTension = 0;

    cin >> n;

    vector<int> tensions(n);

    for (int &tension : tensions) {
        cin >> tension;
    }

    sort(tensions.begin(), tensions.end(), greater<>());

    for (int i = 0; i < n; i++) {
        maxTotalTension = max(maxTotalTension, (i + 1) * tensions[i]);
    }

    cout << maxTotalTension << '\n';

    return 0;
}
