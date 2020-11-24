#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string a;
    int b;

    cin >> a >> b;

    sort(a.rbegin(), a.rend());

    while (true) {
        if (a[0] != '0' && stoi(a) <= b) {
            cout << a << '\n';

            return 0;
        }

        if (!prev_permutation(a.begin(), a.end())) break;
    }

    cout << "-1\n";

    return 0;
}
