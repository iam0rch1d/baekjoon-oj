#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numFactor;

    cin >> numFactor;

    vector<int> factors(numFactor);

    for (int &factor : factors) {
        cin >> factor;
    }

    cout << *max_element(factors.begin(), factors.end()) * *min_element(factors.begin(), factors.end()) << '\n';

    return 0;
}
