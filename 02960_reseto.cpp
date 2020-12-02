#include <iostream>
#include <vector>

using namespace std;

bool isSieved[1001];

int main() {
    int n;
    int k;
    vector<int> erasedNumbers;

    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        if (isSieved[i]) continue;

        for (int j = i; j <= n; j += i) {
            if (!isSieved[j]) {
                isSieved[j] = true;

                erasedNumbers.push_back(j);
            }
        }
    }

    cout << erasedNumbers[k - 1] << '\n';

    return 0;
}
