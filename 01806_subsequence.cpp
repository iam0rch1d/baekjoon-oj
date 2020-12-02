#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int s;
    int sum;
    int left = 0;
    int right = 0;
    int minLength = 100001;

    cin >> n >> s;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    sum = a[0];

    while (right < n) {
        if (sum < s) sum += a[++right];
        else {
            minLength = min(minLength, right - left + 1);
            sum -= a[left++];
        }
    }

    cout << (minLength == 100001 ? 0 : minLength) << '\n';

    return 0;
}
