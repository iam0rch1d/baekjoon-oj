#include <iostream>
#include <vector>

using namespace std;

bool eratosthenesSieve[1001];

int main() {
    int n;
    int k;
    vector<int> erasedNumbers;

    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        if (eratosthenesSieve[i]) continue;

        for (int j = i; j <= n; j += i) {
            if (!eratosthenesSieve[j]) {
                eratosthenesSieve[j] = true;

                erasedNumbers.push_back(j);
            }
        }
    }

    cout << erasedNumbers[k - 1] << '\n';

    return 0;
}
