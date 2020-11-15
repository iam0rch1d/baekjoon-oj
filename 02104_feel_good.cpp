#include <iostream>

using namespace std;

long long a[100000];

long long dncMaxScore(int left, int right) {
    if (left == right) return a[left] * a[left];

    int mid = (left + right) / 2;
    long long maxScore = max(dncMaxScore(left, mid), dncMaxScore(mid + 1, right));
    int spanningLeft = mid;
    int spanningRight = mid + 1;
    long long spanningSum = a[spanningLeft] + a[spanningRight];
    long long minSpanningA = min(a[spanningLeft], a[spanningRight]);

    maxScore = max(maxScore, spanningSum * minSpanningA);

    while (spanningLeft > left || spanningRight < right) {
        if (spanningLeft > left && (spanningRight == right || a[spanningLeft - 1] > a[spanningRight + 1])) {
            spanningSum += a[--spanningLeft];
            minSpanningA = min(minSpanningA, a[spanningLeft]);
        } else {
            spanningSum += a[++spanningRight];
            minSpanningA = min(minSpanningA, a[spanningRight]);
        }

        maxScore = max(maxScore, spanningSum * minSpanningA);
    }

    return maxScore;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << dncMaxScore(0, n - 1) << '\n';

    return 0;
}
