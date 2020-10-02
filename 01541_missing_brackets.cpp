#include <algorithm>
#include <iostream>
#include <vector>

#define MAX_NUM_OPERAND 25

using namespace std;

int main() {
    string formula;
    int operand = 0;
    vector<int> operands;
    int indexFirstMinus = MAX_NUM_OPERAND;
    int operationResult = 0;

    cin >> formula;

    for (int i = 0; i < formula.size(); i++) {
        if (formula.at(i) >= '0' && formula.at(i) <= '9') {
            operand *= 10;
            operand += formula.at(i) - '0';
        }

        if (formula.at(i) < '0' || formula.at(i) > '9' || i == formula.size() - 1) {
            operands.push_back(operand);
            operand = 0;
        }

        if (formula.at(i) == '-' && indexFirstMinus == MAX_NUM_OPERAND) indexFirstMinus = operands.size();
    }

    for (int i = 0; i < operands.size(); i++) {
        if (i < indexFirstMinus) operationResult += operands[i];
        else operationResult -= operands[i];
    }

    cout << operationResult << '\n';

    return 0;
}
