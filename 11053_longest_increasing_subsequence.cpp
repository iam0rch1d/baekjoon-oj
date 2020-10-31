#include <algorithm>
#include <iostream>

using namespace std;

int a[1000];
int maxLengthCache[1000];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) maxLengthCache[i] = max(maxLengthCache[i], maxLengthCache[j] + 1);
        }
    }

    cout << *max_element(maxLengthCache, maxLengthCache + n) + 1 << '\n';

    return 0;
}
