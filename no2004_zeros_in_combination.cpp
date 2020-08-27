#include <algorithm>
#include <iostream>

using namespace std;

int countFactorialFactor(int factorialSize, int factor) {
    int numFactorialFactor = 0;

    while (factorialSize >= factor) {
        numFactorialFactor += factorialSize / factor;
        factorialSize /= factor;
    }

    return numFactorialFactor;
}

int main() {
    int n;
    int m;
    int numFactorialFactor2;
    int numFactorialFactor5;

    cin >> n >> m;

    numFactorialFactor2 = countFactorialFactor(n, 2) - countFactorialFactor(m, 2) - countFactorialFactor(n - m, 2);
    numFactorialFactor5 = countFactorialFactor(n, 5) - countFactorialFactor(m, 5) - countFactorialFactor(n - m, 5);

    cout << min<int>(numFactorialFactor2, numFactorialFactor5) << endl;

    return 0;
}
