#include <cstring>
#include <iostream>

using namespace std;

#define UNMEMOIZED -1

int a[2000];
int isPalindromeCache[2000][2000];

int memoizeIsPalindrome(int left, int right) {
    if (left >= right) return 1;

    int &isPalindrome = isPalindromeCache[left][right];

    if (isPalindrome != UNMEMOIZED) return isPalindrome;

    return isPalindrome = memoizeIsPalindrome(left + 1, right - 1) * (a[left] == a[right]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    memset(isPalindromeCache, UNMEMOIZED, sizeof(isPalindromeCache));

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;

    while (m--) {
        int s;
        int e;

        cin >> s >> e;

        cout << memoizeIsPalindrome(s - 1, e - 1) << '\n';
    }

    return 0;
}
