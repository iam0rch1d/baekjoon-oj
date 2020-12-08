#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long nC2(long long n) {
    return n * (n - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    stack<int> rightGreaterIndices;
    stack<int> rightLessIndices;
    stack<int> leftGreaterIndices;
    stack<int> leftLessIndices;
    long long priceSum = 0;

    cin >> n;

    vector<int> a(n);
    vector<int> rightGreater(n, n);
    vector<int> rightLess(n, n);
    vector<int> leftGreater(n, -1);
    vector<int> leftLess(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    rightGreaterIndices.push(0);
    rightLessIndices.push(0);
    leftGreaterIndices.push(n - 1);
    leftLessIndices.push(n - 1);

    for (int i = 1; i < n; i++) {
        while (!rightGreaterIndices.empty() && a[rightGreaterIndices.top()] <= a[i]) {
            rightGreater[rightGreaterIndices.top()] = i;

            rightGreaterIndices.pop();
        }

        while (!rightLessIndices.empty() && a[rightLessIndices.top()] >= a[i]) {
            rightLess[rightLessIndices.top()] = i;

            rightLessIndices.pop();
        }

        rightGreaterIndices.push(i);
        rightLessIndices.push(i);
    }

    for (int i = n - 2; i >= 0; i--) {
        while (!leftGreaterIndices.empty() && a[leftGreaterIndices.top()] < a[i]) {
            leftGreater[leftGreaterIndices.top()] = i;

            leftGreaterIndices.pop();
        }

        while (!leftLessIndices.empty() && a[leftLessIndices.top()] > a[i]) {
            leftLess[leftLessIndices.top()] = i;

            leftLessIndices.pop();
        }

        leftGreaterIndices.push(i);
        leftLessIndices.push(i);
    }

    for (int i = 0; i < n; i++) {
        int right = max(i, rightGreater[i] - 1);
        int left = min(i, leftGreater[i] + 1);

        priceSum += (nC2(right - left + 1) - nC2(i - left) - nC2(right - i)) * a[i];
    }

    for (int i = 0; i < n; i++) {
        int right = max(i, rightLess[i] - 1);
        int left = min(i, leftLess[i] + 1);

        priceSum -= (nC2(right - left + 1) - nC2(i - left) - nC2(right - i)) * a[i];
    }

    cout << priceSum << '\n';

    return 0;
}
