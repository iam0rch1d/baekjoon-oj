#include <iostream>

using namespace std;

int main() {
    int number;
    int multiplyingNumber;
    int factorialFactor5Count = 0;

    cin >> number;

    if (number < 5) {
        cout << "0" << endl;

        return 0;
    }

    for (int i = 5; i <= number; i += 5) {
        multiplyingNumber = i;

        while (multiplyingNumber % 5 == 0) {
            factorialFactor5Count++;
            multiplyingNumber /= 5;
        }
    }

    cout << factorialFactor5Count << endl;

    return 0;
}
