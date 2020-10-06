#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> permutation(n);

    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    while (true) {
        for (int element : permutation) {
            cout << element << ' ';
        }

        cout << '\n';

        if (!next_permutation(permutation.begin(), permutation.end())) break;
    }

    return 0;
}
