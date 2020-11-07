#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    map<string, int> indexOf;

    cin >> n >> m;

    vector<string> nameOf(n);

    for (int i = 0; i < n; i++) {
        string name;

        cin >> name;

        indexOf[name] = i;
        nameOf[i] = name;
    }

    for (int i = 0; i < m; i++) {
        string query;

        cin >> query;

        if (query[0] >= '0' && query[0] <= '9') cout << nameOf[stoi(query) - 1];
        else cout << indexOf.find(query)->second + 1;

        cout << '\n';
    }

    return 0;
}
