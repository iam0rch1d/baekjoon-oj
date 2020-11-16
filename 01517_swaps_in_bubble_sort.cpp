#include <iostream>

using namespace std;

int a[500000];
int cache[500000];

long long dncSwapCount(int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    long long swapCount = dncSwapCount(left, mid) + dncSwapCount(mid + 1, right);
    int leftHeadIndex = left;
    int rightHeadIndex = mid + 1;
    int cacheHeadIndex = 0;

    while (leftHeadIndex <= mid || rightHeadIndex <= right) {
        if (leftHeadIndex <= mid
            && (rightHeadIndex > right || a[leftHeadIndex] <= a[rightHeadIndex])) {
            cache[cacheHeadIndex++] = a[leftHeadIndex++];
        } else {
            swapCount += (long long) (mid - leftHeadIndex + 1);
            cache[cacheHeadIndex++] = a[rightHeadIndex++];
        }
    }

    for (int i = left; i <= right; i++) {
        a[i] = cache[i - left];
    }

    return swapCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << dncSwapCount(0, n - 1) << '\n';

    return 0;
}
