#include <iostream>

using namespace std;

#define MODULO 1000000

int dp[5001] = {1};

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

        if (codeNumbers[i] != 0) dp[i] = (dp[i] + dp[i - 1]) % MODULO;

        if (parsedTwoDigit >= 10 && parsedTwoDigit <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % MODULO;
        }
    }

    cout << dp[codeSize] << '\n';

    return 0;
}
