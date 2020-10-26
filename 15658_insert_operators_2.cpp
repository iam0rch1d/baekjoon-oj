#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int a[11];
vector<int> results;

void backtrackResult(int index, int currentResult, int pluses, int minuses, int multiplications, int divisions) {
    if (index == n) {
        results.push_back(currentResult);

        return;
    }

    if (pluses > 0) {
        backtrackResult(index + 1,
                        currentResult + a[index],
                        pluses - 1, minuses, multiplications, divisions);
    }

    if (minuses > 0)
        backtrackResult(index + 1,
                        currentResult - a[index],
                        pluses, minuses - 1, multiplications, divisions);

    if (multiplications > 0)
        backtrackResult(index + 1,
                        currentResult * a[index],
                        pluses, minuses, multiplications - 1, divisions);

    if (divisions > 0)
        backtrackResult(index + 1,
                        currentResult / a[index],
                        pluses, minuses, multiplications, divisions - 1);
}

int main() {
    int pluses;
    int minuses;
    int multiplications;
    int divisions;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> pluses >> minuses >> multiplications >> divisions;

    backtrackResult(1, a[0], pluses, minuses, multiplications, divisions);

    cout << *max_element(results.begin(), results.end()) << '\n'
         << *min_element(results.begin(), results.end()) << '\n';

    return 0;
}
