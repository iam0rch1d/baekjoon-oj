#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool canMake[1001];

int main() {
    int n;
    int numberCount = 0;

    cin >> n;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            for (int k = 0; k <= n - i - j; k++) {
                canMake[i + 5 * j + 10 * k + 50 * (n - i - j - k)] = true;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (canMake[i]) numberCount++;
    }

    cout << numberCount << '\n';

    return 0;
}
