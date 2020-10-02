#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int operate(vector<int> &operands, vector<int> &operationSequence) {
    int result = operands[0];

    for (int i = 0; i < operationSequence.size(); i++) {
        switch (operationSequence[i]) {
            case 0: {
                result += operands[i + 1];

                break;
            }
            case 1: {
                result -= operands[i + 1];

                break;
            }
            case 2: {
                result *= operands[i + 1];

                break;
            }
            default: {
                result /= operands[i + 1];

                break;
            }
        }
    }

    return result;
}

void backtrackResult(vector<int> &operands,
                     int *numOperations,
                     vector<int> &operationSequence,
                     vector<int> &results) {
    int result;

    if (operationSequence.size() == operands.size() - 1) {
        result = operate(operands, operationSequence);

        results.push_back(result);
    } else {
        for (int i = 0; i < 4; i++) {
            if (numOperations[i] > 0) {
                numOperations[i]--;
                operationSequence.push_back(i);

                backtrackResult(operands, numOperations, operationSequence, results);

                numOperations[i]++;
                operationSequence.pop_back();
            }
        }
    }
}

int main() {
    int numOperand;
    int numOperations[4];
    vector<int> operationSequence;
    vector<int> results;

    cin >> numOperand;

    vector<int> operands(numOperand);

    for (int &operand : operands) {
        cin >> operand;
    }

    for (int &numOperation : numOperations) {
        cin >> numOperation;
    }

    backtrackResult(operands, numOperations, operationSequence, results);
    sort(results.begin(), results.end());

    cout << results.back() << '\n' << results[0];

    return 0;
}
