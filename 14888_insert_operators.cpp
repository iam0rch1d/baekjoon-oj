#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> operations;
    vector<int> results;

    cin >> n;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    for (int i = 0; i < 4; i++) {
        int numOperation;

        cin >> numOperation;

        for (int j = 0; j < numOperation; j++) {
            operations.push_back(i);
        }
    }

    while (true) {
        int result = a[0];

        for (int i = 0; i < n - 1; i++) {
            if (operations[i] == 0) result += a[i + 1];
            else if (operations[i] == 1) result -= a[i + 1];
            else if (operations[i] == 2) result *= a[i + 1];
            else result /= a[i + 1];
        }

        results.push_back(result);

        if (!next_permutation(operations.begin(), operations.end())) break;
    }

    cout << *max_element(results.begin(), results.end()) << '\n'
         << *min_element(results.begin(), results.end()) << '\n';

    return 0;
}
