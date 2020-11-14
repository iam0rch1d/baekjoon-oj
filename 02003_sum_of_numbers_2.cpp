#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    int sum = 0;
    int leftHeadIndex = 0;
    int rightHeadIndex = 0;
    int mCount = 0;

    cin >> n >> m;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    while (true) {
        if (sum >= m) sum -= a[leftHeadIndex++];
        else if (rightHeadIndex == n) break;
        else sum += a[rightHeadIndex++];

        if (sum == m) mCount++;
    }

    cout << mCount << '\n';

    return 0;
}
