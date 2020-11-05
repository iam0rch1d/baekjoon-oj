#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long b;
    long long c;
    long long supervisors = 0;

    cin >> n;

    vector<long long> a(n);

    for (long long &ai : a) {
        cin >> ai;
    }

    cin >> b >> c;

    for (long long ai : a) {
        supervisors += max((ai - b + c - 1) / c + 1, 1ll);
    }

    cout << supervisors << '\n';

    return 0;
}
