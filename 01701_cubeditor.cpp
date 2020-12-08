#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    int n;
    int maxPrefixSize = 0;

    cin >> s;

    n = s.size();

    while (!s.empty()) {
        int prefixIndex = 0;

        vector<int> failure(n);

        failure[0] = 0;

        for (int i = 1; i < n; i++) {
            if (prefixIndex && s[i] != s[prefixIndex]) prefixIndex = failure[prefixIndex - 1];

            if (s[i] == s[prefixIndex]) failure[i] = ++prefixIndex;
            else prefixIndex = 0;
        }

        maxPrefixSize = max(maxPrefixSize, *max_element(failure.begin(), failure.end()));

        s.erase(s.begin());
        n--;
    }

    cout << maxPrefixSize << '\n';

    return 0;
}
