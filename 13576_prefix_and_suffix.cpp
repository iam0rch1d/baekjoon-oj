#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int failureCounts[100001];

int main() {
    string s;
    int n;
    int prefixIndex = 0;
    stack<pair<int, int>> prefixes;

    cin >> s;

    n = s.size();

    vector<int> failures(n);

    failures[0] = 0;

    for (int i = 1; i < n; i++) {
        while (prefixIndex && s[i] != s[prefixIndex]) prefixIndex = failures[prefixIndex - 1];

        if (s[i] == s[prefixIndex]) failures[i] = ++prefixIndex;
        else prefixIndex = 0;
    }

    for (int i = 0; i < n; i++) {
        failureCounts[failures[i]]++;
    }

    for (int i = n; i > 0; i--) {
        failureCounts[failures[i - 1]] += failureCounts[i];
    }

    prefixIndex = n;

    while (prefixIndex) {
        prefixes.push({prefixIndex, failureCounts[prefixIndex] + 1});

        prefixIndex = failures[prefixIndex - 1];
    }

    cout << prefixes.size() << '\n';

    while (!prefixes.empty()) {
        cout << prefixes.top().first << ' ' << prefixes.top().second << '\n';

        prefixes.pop();
    }

    return 0;
}
