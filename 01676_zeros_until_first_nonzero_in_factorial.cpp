#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int number;
    int multiplyingNumber;
    int factorialFactor2Count = 0;
    int factorialFactor5Count = 0;

    cin >> number;

    if (number < 5) {
        cout << "0" << endl;

        return 0;
    }

    for (int i = 2; i <= number; i++) {
        multiplyingNumber = i;

        while (multiplyingNumber % 2 == 0 || multiplyingNumber % 5 == 0) {
            if (multiplyingNumber % 2 == 0) {
                factorialFactor2Count++;
                multiplyingNumber /= 2;
            }

            if (multiplyingNumber % 5 == 0) {
                factorialFactor5Count++;
                multiplyingNumber /= 5;
            }
        }
    }

    cout << min<int>(factorialFactor2Count, factorialFactor5Count) << endl;

    return 0;
}
