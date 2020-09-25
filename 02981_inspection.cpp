#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int differencesGcd;
    vector<int> differenceCommonDivisors;

    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    differencesGcd = numbers[1] - numbers[0];

    for (int i = 2; i < n; i++) {
        differencesGcd = __gcd(differencesGcd, numbers[i] - numbers[0]);
    }

    for (int i = 1; i * i <= differencesGcd; i++) {
        if (differencesGcd % i == 0) {
            if (i != 1) differenceCommonDivisors.push_back(i);

            if (i * i != differencesGcd) differenceCommonDivisors.push_back(differencesGcd / i);
        }
    }

    sort(differenceCommonDivisors.begin(), differenceCommonDivisors.end());

    for (int differenceCommonDivisor : differenceCommonDivisors) {
        cout << differenceCommonDivisor << ' ';
    }

    cout << '\n';

    return 0;
}
