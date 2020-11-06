#include <iostream>

using namespace std;

int main() {
    int dateDigit;
    int violationCount = 0;

    cin >> dateDigit;

    for (int i = 0; i < 5; i++) {
        int carDigit;

        cin >> carDigit;

        violationCount += carDigit == dateDigit;
    }

    cout << violationCount << '\n';

    return 0;
}
