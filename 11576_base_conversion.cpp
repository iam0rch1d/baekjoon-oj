#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int futureBase;
    int jeongBase;
    int futureNumberDigitSize;
    int place = 1;
    int decimal = 0;
    vector<int> jeongNumberDigits;

    cin >> futureBase >> jeongBase >> futureNumberDigitSize;

    vector<int> futureNumberDigits(futureNumberDigitSize);

    for (int i = 0; i < futureNumberDigitSize - 1; i++) {
        place *= futureBase;
    }

    for (int &futureNumberDigit : futureNumberDigits) {
        cin >> futureNumberDigit;

        decimal += futureNumberDigit * place;
        place /= futureBase;
    }

    if (decimal == 0) {
        cout << "0\n";

        return 0;
    }

    while (decimal > 0) {
        jeongNumberDigits.push_back(decimal % jeongBase);

        decimal /= jeongBase;
    }

    reverse(jeongNumberDigits.begin(), jeongNumberDigits.end());

    for (int jeongNumberDigit : jeongNumberDigits) {
        cout << jeongNumberDigit << ' ';
    }

    cout << '\n';

    return 0;
}
