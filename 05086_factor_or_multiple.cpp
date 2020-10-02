#include <iostream>

using namespace std;

int main() {
    while (true) {
        int numbers[2];

        cin >> numbers[0] >> numbers[1];

        if (numbers[0] == 0 && numbers[1] == 0) return 0;

        cout << ((numbers[0] < numbers[1] && numbers[1] % numbers[0] == 0) ? "factor" :
        (numbers[0] > numbers[1] && numbers[0] % numbers[1] == 0) ? "multiple" : "neither") << '\n';
    }
}
