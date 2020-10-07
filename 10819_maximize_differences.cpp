#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    int a[8];
    int maxFormula = -801;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    while (true) {
        int formula = 0;

        for (int i = 0; i < n - 1; i++) {
            formula += abs(a[i] - a[i + 1]);
        }

        maxFormula = max(maxFormula, formula);

        if (!next_permutation(a, a + n)) break;
    }

    cout << maxFormula << '\n';

    return 0;
}
