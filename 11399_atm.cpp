#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int totalTime = 0;

    cin >> n;

    vector<int> p(n);

    for (int &pi : p) {
        cin >> pi;
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        totalTime += (n - i) * p[i];
    }

    cout << totalTime << '\n';

    return 0;
}
