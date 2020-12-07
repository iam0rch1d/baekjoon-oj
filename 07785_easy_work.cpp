#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    set<string> office;

    cin >> n;

    while (n--) {
        string name;
        string query;

        cin >> name >> query;

        if (query == "enter") office.insert(name);
        else office.erase(name);
    }

    for (auto i = office.rbegin(); i != office.rend(); i++) {
        cout << *i << '\n';
    }

    return 0;
}
