#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int main() {
    long long s;
    long long t;

    cin >> s >> t;

    if (s == t) {
        cout << "0\n";

        return 0;
    }

    set<long long> creatableNumbers;
    queue<pair<long long, string>> bfsOperations;

    creatableNumbers.insert(s);
    bfsOperations.push({s, ""});

    while (!bfsOperations.empty()) {
        long long currentNumber;
        string currentRecipe;

        tie(currentNumber, currentRecipe) = bfsOperations.front();

        bfsOperations.pop();

        if (currentNumber == t) {
            cout << currentRecipe << '\n';

            return 0;
        }

        for (int i = 0; i < 4; i++) {
            long long nextNumber = 0;

            if (i == 0) nextNumber = currentNumber * currentNumber;
            else if (i == 1) nextNumber = currentNumber + currentNumber;
            else if (i == 2) nextNumber = 0;
            else if (currentNumber) nextNumber = 1;

            if (nextNumber >= 0 && nextNumber <= 1000000000 && !creatableNumbers.count(nextNumber)) {
                creatableNumbers.insert(nextNumber);
                bfsOperations.push({nextNumber, currentRecipe + "*+-/"[i]});
            }
        }
    }

    cout << "-1\n";

    return 0;
}
