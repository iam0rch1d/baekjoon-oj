#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTarget;
    vector<int> numberStack;
    vector<char> operationStack;
    int targetNo = 0;

    cin >> numTarget;

    vector<int> targets(numTarget);

    for (int &target : targets) {
        cin >> target;
    }

    for (int i = 1; i <= numTarget; i++) {
        numberStack.push_back(i);
        operationStack.push_back('+');

        while (!numberStack.empty() && numberStack.back() == targets[targetNo]) {
            numberStack.pop_back();
            operationStack.push_back('-');

            targetNo++;
        }
    }

    if (numberStack.empty()) {
        for (char &operation : operationStack) {
            cout << operation << "\n";
        }
    } else cout << "NO\n";

    return 0;
}
