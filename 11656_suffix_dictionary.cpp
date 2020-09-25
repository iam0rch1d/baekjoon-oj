#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;

    cin >> s;

    vector<string> suffices(s.size());

    for (int i = 0; i < s.size(); i++) {
        suffices[i] = s.substr(i, s.size());
    }

    sort(suffices.begin(), suffices.end(), [](auto i, auto j) { return i.compare(j) < 0; });

    for (const auto &suffix : suffices) {
        cout << suffix << '\n';
    }

    return 0;
}
