#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    string p;
    int n;
    int m;
    int prefixIndex = 0;
    vector<int> substringIndices;

    cin >> s >> p;

    n = s.size();
    m = p.size();

    vector<int> failures(m);

    failures[0] = 0;

    for (int i = 1; i < m; i++) {
        while (prefixIndex && p[i] != p[prefixIndex]) {
            prefixIndex = failures[prefixIndex - 1];
        }

        if (p[i] == p[prefixIndex]) failures[i] = ++prefixIndex;
        else prefixIndex = 0;
    }

    prefixIndex = 0;

    for (int i = 0; i < n; i++) {
        while (prefixIndex && s[i] != p[prefixIndex]) {
            prefixIndex = failures[prefixIndex - 1];
        }

        if (s[i] == p[prefixIndex]) {
            if (prefixIndex == m - 1) {
                substringIndices.push_back(i - prefixIndex);

                prefixIndex = failures[prefixIndex];
            } else ++prefixIndex;
        }
    }

    cout << !substringIndices.empty() << '\n';

    return 0;
}
