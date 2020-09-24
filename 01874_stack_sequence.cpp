#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTarget;
    stack<int> numbers;
    string operations;
    int targetNo = 0;

    cin >> numTarget;

    vector<int> targets(numTarget);

    for (int &target : targets) {
        cin >> target;
    }

    for (int i = 1; i <= numTarget; i++) {
        numbers.push(i);
        operations += '+';

        while (!numbers.empty() && numbers.top() == targets[targetNo]) {
            numbers.pop();
            operations += '-';

            targetNo++;
        }
    }

    if (numbers.empty()) {
        for (char &operation : operations) {
            cout << operation << '\n';
        }
    } else cout << "NO\n";

    return 0;
}
