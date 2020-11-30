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

        vector<long long> operands1(operands);
        vector<char> operations1(operations);
        vector<long long> operands2;
        vector<char> operations2;
        int operations2Size;
        long long result;

        for (unsigned i = 0; i < operationsSize; i++) {
            if (priorBitset & (1u << i)) {
                operands1[i] = operate(operands1[i], operands1[i + 1], operations1[i]);
                operands1[i + 1] = 0;
                operations1[i] = '.';
            }
        }

        operands2.push_back(operands1[0]);

        for (int i = 0; i < operationsSize; i++) {
            if (operations1[i] == '.') continue;
            else if (operations1[i] == '*') operands2.back() *= operands1[i + 1];
            else {
                operands2.push_back(operands1[i + 1]);
                operations2.push_back(operations1[i]);
            }
        }

        result = operands2[0];
        operations2Size = operations2.size();

        for (int i = 0; i < operations2Size; i++) {
            result = operate(result, operands2[i + 1], operations2[i]);
        }

        maxResult = max(maxResult, result);
    }

    cout << maxResult << '\n';

    return 0;
}
