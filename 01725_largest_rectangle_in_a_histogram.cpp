#include <iostream>
#include <vector>

using namespace std;

long long dncMaxSurface(vector<long long> &h, int left, int right) {
    if (left == right) return h[left];

    int mid = (left + right) / 2;
    long long maxSurface = max(dncMaxSurface(h, left, mid), dncMaxSurface(h, mid + 1, right));
    int spanningLeft = mid;
    int spanningRight = mid + 1;
    long long minSpanningHeight = min(h[spanningLeft], h[spanningRight]);

    maxSurface = max(maxSurface, 2 * minSpanningHeight);

    while (spanningLeft > left || spanningRight < right) {
        if (spanningLeft > left && (spanningRight == right || h[spanningLeft - 1] > h[spanningRight + 1])) {
            minSpanningHeight = min(minSpanningHeight, h[--spanningLeft]);
        } else minSpanningHeight = min(minSpanningHeight, h[++spanningRight]);

        maxSurface = max(maxSurface, minSpanningHeight * (spanningRight - spanningLeft + 1));
    }

    return maxSurface;
}

int main() {
    int n;

    cin >> n;

    vector<long long> h(n);

    for (long long &hi : h) {
        cin >> hi;
    }

    cout << dncMaxSurface(h, 0, n - 1) << '\n';

    return 0;
}
