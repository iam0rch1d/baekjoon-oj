#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numFactor;

    cin >> numFactor;

    vector<int> factors(numFactor);

    for (int i = 0; i < numFactor; i++) {
        cin >> factors[i];
    }

    cout << *max_element(factors.begin(), factors.end()) * *min_element(factors.begin(), factors.end()) << endl;

    return 0;
}
