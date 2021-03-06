#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    int sum;
    int left = 0;
    int right = 0;
    int mCount = 0;

    cin >> n >> m;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    sum = a[0];

    while (right < n) {
        if (sum <= m) {
            mCount += sum == m;
            sum += a[++right];
        } else sum -= a[left++];
    }

    cout << mCount << '\n';

    return 0;
}
