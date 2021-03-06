#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    string s;
    int prefixIndex = 0;

    cin >> n >> s;

    vector<int> failures(n);

    failures[0] = 0;

    for (int i = 1; i < n; i++) {
        while (prefixIndex && s[i] != s[prefixIndex]) {
            prefixIndex = failures[prefixIndex - 1];
        }

        if (s[i] == s[prefixIndex]) failures[i] = ++prefixIndex;
        else prefixIndex = 0;
    }

    cout << n - failures[n - 1] << '\n';

    return 0;
}
