#include <iostream>
#include <vector>

using namespace std;

int failureCounts[1000001];

int main() {
    string s;
    int n;
    int prefixIndex = 0;

    cin >> s;

    n = s.size();

    vector<int> failures(n);

    failures[0] = 0;

    for (int i = 1; i < n; i++) {
        while (prefixIndex && s[i] != s[prefixIndex]) {
            prefixIndex = failures[prefixIndex - 1];
        }

        if (s[i] == s[prefixIndex]) failures[i] = ++prefixIndex;
        else prefixIndex = 0;
    }

    for (int i = 1; i < n - 1; i++) {
        failureCounts[failures[i]]++;
    }

    prefixIndex = n;

    while (prefixIndex) {
        if (failureCounts[prefixIndex]) {
            cout << s.substr(0, prefixIndex) << '\n';

            return 0;
        }

        prefixIndex = failures[prefixIndex - 1];
    }

    cout << "-1\n";

    return 0;
}
