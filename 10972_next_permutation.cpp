#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    bool hasNextPermutation;

    cin >> n;

    vector<int> permutation(n);

    for (int &element : permutation) {
        cin >> element;
    }

    hasNextPermutation = next_permutation(permutation.begin(), permutation.end());

    if (hasNextPermutation) {
        for (int element : permutation) {
            cout << element << ' ';
        }
    } else cout << "-1";

    cout << '\n';

    return 0;
}
