#include <iostream>
#include <vector>

using namespace std;

long long operate(long long operand1, long long operand2, char operation) {
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else return operand1 * operand2;
}

int main() {
    int n;
    string s;
    unsigned operationsSize;
    vector<long long> operands;
    vector<char> operations;
    long long maxResult = INT32_MIN;

    cin >> n >> s;

    if (n == 1) {
        cout << s << '\n';

        return 0;
    }

    operationsSize = n / 2;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) operands.push_back(s[i] - '0');
        else operations.push_back(s[i]);
    }

    for (unsigned priorBitset = 0; priorBitset < (1u << operationsSize); priorBitset++) {
        bool isValid = true;

        for (unsigned i = 0; i < operationsSize - 1u; i++) {
            if ((priorBitset & (1u << i)) && (priorBitset & (1u << (i + 1u)))) {
                isValid = false;

                break;
            }
        }

        if (!isValid) continue;

        vector<long long> tempOperands(operands);
        vector<char> tempOperations(operations);
        long long result;

        for (unsigned i = 0; i < operationsSize; i++) {
            if (priorBitset & (1u << i)) {
                tempOperands[i] = operate(tempOperands[i], tempOperands[i + 1], tempOperations[i]);
                tempOperands[i + 1] = 0;
                tempOperations[i] = '+';
            }
        }

        result = tempOperands[0];

        for (unsigned i = 0; i < operationsSize; i++) {
            result = operate(result, tempOperands[i + 1], tempOperations[i]);
        }

        maxResult = max(maxResult, result);
    }

    cout << maxResult << '\n';

    return 0;
}
