#include <iostream>
#include <vector>

using namespace std;

long long dncMaxSurface(vector<long long> &h, int left, int right) {
    if (left == right) return h[left];

    int mid = (left + right) / 2;
    long long maxSurface = max(dncMaxSurface(h, left, mid), dncMaxSurface(h, mid + 1, right));
    int stretchedLeft = mid;
    int stretchedRight = mid + 1;
    long long stretchedHeight = min(h[stretchedLeft], h[stretchedRight]);

    maxSurface = max(maxSurface, 2 * stretchedHeight);

    while (stretchedLeft > left || stretchedRight < right) {
        if (stretchedRight < right && (stretchedLeft == left || h[stretchedLeft - 1] < h[stretchedRight + 1])) {
            stretchedRight++;
            stretchedHeight = min(stretchedHeight, h[stretchedRight]);
        } else {
            stretchedLeft--;
            stretchedHeight = min(stretchedHeight, h[stretchedLeft]);
        }

        maxSurface = max(maxSurface, stretchedHeight * (stretchedRight - stretchedLeft + 1));
    }

    return maxSurface;
}

int main() {
    while (true) {
        int n;

        cin >> n;

        if (n == 0) return 0;

        vector<long long> h(n);

        for (long long &hi : h) {
            cin >> hi;
        }

        cout << dncMaxSurface(h, 0, n - 1) << '\n';
    }
}
