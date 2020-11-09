#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> x(n);
    vector<int> compressed(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];

        compressed[i] = x[i];
    }

    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

    for (int xi : x) {
        cout << lower_bound(compressed.begin(), compressed.end(), xi) - compressed.begin() << ' ';
    }

    cout << '\n';

    return 0;
}
