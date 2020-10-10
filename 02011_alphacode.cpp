#include <iostream>

#define MODULO 1000000

using namespace std;

int decodeCountCache[5001] = {1};

int main() {
    string code;
    int codeSize;
    int codeNumbers[5001] = {0};

    cin >> code;

    codeSize = code.size();

    for (int i = 0; i < codeSize; i++) {
        codeNumbers[i + 1] = code[i] - '0';
    }

    for (int i = 1; i <= codeSize; i++) {
        int parsedTwoDigit = codeNumbers[i - 1] * 10 + codeNumbers[i];

        if (codeNumbers[i] != 0) decodeCountCache[i] = (decodeCountCache[i] + decodeCountCache[i - 1]) % MODULO;

        if (parsedTwoDigit >= 10 && parsedTwoDigit <= 26) {
            decodeCountCache[i] = (decodeCountCache[i] + decodeCountCache[i - 2]) % MODULO;
        }
    }

    cout << decodeCountCache[codeSize] << '\n';

    return 0;
}
