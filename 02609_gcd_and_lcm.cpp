#include <cmath>
#include <iostream>

using namespace std;

int euclid(int a, int b) {
    if (b > a) return euclid(b, a);

    if (a % b == 0) return b;

    return euclid(b, a - b);
}

int main() {
    int numbers[2];
    int gcd;

    cin >> numbers[0] >> numbers[1];

    gcd = euclid(numbers[0], numbers[1]);

    cout << gcd << endl << numbers[0] * numbers[1] / gcd << endl;

    return 0;
}
