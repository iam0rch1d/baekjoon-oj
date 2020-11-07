#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string formula;
    bool isMinusAppeared = false;
    vector<int> operands;
    vector<int> coefficients(1, 1);
    string operandString;
    int result = 0;

    cin >> formula;

    for (int i = 0; i < formula.size(); i++) {
        if (formula[i] == '+' || formula[i] == '-') {
            operands.push_back(stoi(operandString));
            operandString.clear();

            if (formula[i] == '-' && !isMinusAppeared) isMinusAppeared = true;

            coefficients.push_back(isMinusAppeared ? -1 : 1);
        } else operandString.push_back(formula[i]);

        if (i == formula.size() - 1) {
            operands.push_back(stoi(operandString));
            coefficients.push_back(isMinusAppeared ? -1 : 1);
        }
    }

    for (int i = 0; i < operands.size(); i++) {
        result += coefficients[i] * operands[i];
    }

    cout << result << '\n';

    return 0;
}
