#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numDividend;
    int differencesGcd;
    vector<int> differencesCommonDivisors;

    cin >> numDividend;

    vector<int> dividends(numDividend);
    vector<int> differences(numDividend - 1);

    for (int &dividend : dividends) {
        cin >> dividend;
    }

    sort(dividends.begin(), dividends.end());

    differencesGcd = dividends[1] - dividends[0];

    for (int i = 0; i < numDividend - 1; i++) {
        differences[i] = dividends[i + 1] - dividends[0];
        differencesGcd = __gcd(differencesGcd, differences[i]);
    }

    for (int i = 1; i * i <= differencesGcd; i++) {
        if (differencesGcd % i == 0) {
            if (i != 1) differencesCommonDivisors.push_back(i);

            if (i != differencesGcd / i) differencesCommonDivisors.push_back(differencesGcd / i);
        }
    }

    sort(differencesCommonDivisors.begin(), differencesCommonDivisors.end());

    for (int &differencesCommonDivisor : differencesCommonDivisors) {
        cout << differencesCommonDivisor << ' ';
    }

    cout << endl;

    return 0;
}
