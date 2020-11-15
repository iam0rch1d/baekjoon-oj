#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    map<string, string> sites;

    cin >> n >> m;

    while (n--) {
        string url;
        string password;

        cin >> url >> password;

        sites.insert({url, password});
    }

    while (m--) {
        string url;

        cin >> url;
        cout << sites.find(url)->second << '\n';
    }

    return 0;
}
