#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int number;
    int multiplyingNumber;
    int numFactorialFactor2 = 0;
    int numFactorialFactor5 = 0;

    cin >> number;

    if (number < 5) {
        cout << "0" << endl;

        return 0;
    }

    for (int i = 2; i <= number; i++) {
        multiplyingNumber = i;

        while (multiplyingNumber % 2 == 0 || multiplyingNumber % 5 == 0) {
            if (multiplyingNumber % 2 == 0) {
                numFactorialFactor2++;
                multiplyingNumber /= 2;
            }

            if (multiplyingNumber % 5 == 0) {
                numFactorialFactor5++;
                multiplyingNumber /= 5;
            }
        }
    }

    cout << min<int>(numFactorialFactor2, numFactorialFactor5) << endl;

    return 0;
}
