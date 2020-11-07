#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    set<string> names;
    set<string> dbjs;

    cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        string name;

        cin >> name;

        if (names.find(name) != names.end()) dbjs.insert(name);
        else names.insert(name);
    }

    cout << dbjs.size() << '\n';

    for (auto &dbj : dbjs) {
        cout << dbj << '\n';
    }

    return 0;
}
