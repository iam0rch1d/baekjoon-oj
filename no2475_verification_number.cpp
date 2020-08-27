#include <iostream>

using namespace std;

int main() {
    int uniqueNumbers[5];
    int uniqueNumbersSquareSum = 0;

    for (int &uniqueNumber : uniqueNumbers) {
        cin >> uniqueNumber;
        uniqueNumbersSquareSum += uniqueNumber * uniqueNumber;
    }

    cout << uniqueNumbersSquareSum % 10 << endl;

    return 0;
}
