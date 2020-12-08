#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    int prefixIndex = 0;

    cin >> n >> s;

    vector<int> failure(n);

    failure[0] = 0;

    for (int i = 1; i < n; i++) {
        if (prefixIndex && s[i] != s[prefixIndex]) prefixIndex = failure[prefixIndex - 1];

        if (s[i] == s[prefixIndex]) failure[i] = ++prefixIndex;
        else prefixIndex = 0;
    }

    cout << n - failure[n - 1] << '\n';

    return 0;
}
