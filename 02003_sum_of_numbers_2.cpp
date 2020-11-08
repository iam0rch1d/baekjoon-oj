#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    int sum = 0;
    int aLeftIndex = 0;
    int aRightIndex = 0;
    int mCount = 0;

    cin >> n >> m;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    while (true) {
        if (sum >= m) sum -= a[aLeftIndex++];
        else if (aRightIndex == n) break;
        else sum += a[aRightIndex++];

        if (sum == m) mCount++;
    }

    cout << mCount << '\n';

    return 0;
}
