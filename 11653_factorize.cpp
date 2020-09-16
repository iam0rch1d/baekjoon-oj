#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int number;
    int divisor = 2;

    cin >> number;

    while (divisor <= number) {
        if (number % divisor == 0) {
            number /= divisor;

            cout << divisor << endl;
        } else divisor++;
    }

    return 0;
}
