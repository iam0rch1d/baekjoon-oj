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
    int factorialFactor2Count;
    int factorialFactor5Count;

    cin >> n >> m;

    factorialFactor2Count = countFactorialFactor(n, 2) - countFactorialFactor(m, 2) - countFactorialFactor(n - m, 2);
    factorialFactor5Count = countFactorialFactor(n, 5) - countFactorialFactor(m, 5) - countFactorialFactor(n - m, 5);

    cout << min(factorialFactor2Count, factorialFactor5Count) << endl;

    return 0;
}
