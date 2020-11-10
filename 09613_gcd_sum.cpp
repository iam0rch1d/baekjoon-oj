#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testcases;

    cin >> testcases;

    while (testcases--) {
        int n;
        long long gcdSum = 0;

        cin >> n;

        vector<int> numbers(n);

        for (int &number : numbers) {
            cin >> number;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdSum += __gcd(numbers[i], numbers[j]);
            }
        }

        cout << gcdSum << '\n';
    }

    return 0;
}
