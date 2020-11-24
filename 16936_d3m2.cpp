#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<pair<int, long long>> a(n);

    for (auto &ai : a) {
        ai.first = 0;

        cin >> ai.second;

        long long divisor = 3;

        while (ai.second % divisor == 0) {
            divisor *= 3;
            ai.first--;
        }
    }

    sort(a.begin(), a.end());

    for (auto &ai : a) {
        cout << ai.second << ' ';
    }

    cout << '\n';

    return 0;
}
