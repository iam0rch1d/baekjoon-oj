#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int euclid(int a, int b) {
    if (b > a) return euclid(b, a);

    if (a % b == 0) return b;

    return euclid(b, a - b);
}

int main() {
    int numDividend;
    int differencesGcd;
    int differencesGcdSquareRoot;
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
        differencesGcd = euclid(differencesGcd, differences[i]);
    }

    differencesGcdSquareRoot = sqrt(differencesGcd);

    for (int i = 1; i <= differencesGcdSquareRoot; i++) {
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
