#include <cstring>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool isVisited[10000];
char commandFor[10000];
int previousRegisters[10000];

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int a;
        int b;
        queue<int> bfsRegisters;

        cin >> a >> b;

        isVisited[a] = true;

        bfsRegisters.push(a);

        while (!bfsRegisters.empty()) {
            int currentRegister = bfsRegisters.front();

            bfsRegisters.pop();

            if (currentRegister == b) {
                stack<int> tracebackRegisters;

                while (currentRegister != a) {
                    tracebackRegisters.push(currentRegister);

                    currentRegister = previousRegisters[currentRegister];
                }

                while (!tracebackRegisters.empty()) {
                    cout << commandFor[tracebackRegisters.top()];

                    tracebackRegisters.pop();
                }

                cout << '\n';

                break;
            }

            int adjacentRegisters[] = {2 * currentRegister % 10000,
                                       (currentRegister + 9999) % 10000,
                                       10 * currentRegister % 10000 + currentRegister / 1000,
                                       currentRegister % 10 * 1000 + currentRegister / 10};

            for (int i = 0; i < 4; i++) {
                if (!isVisited[adjacentRegisters[i]]) {
                    isVisited[adjacentRegisters[i]] = true;
                    previousRegisters[adjacentRegisters[i]] = currentRegister;

                    if (i == 0) commandFor[adjacentRegisters[i]] = 'D';
                    else if (i == 1) commandFor[adjacentRegisters[i]] = 'S';
                    else if (i == 2) commandFor[adjacentRegisters[i]] = 'L';
                    else if (i == 3) commandFor[adjacentRegisters[i]] = 'R';

                    bfsRegisters.push(adjacentRegisters[i]);
                }
            }
        }

        memset(isVisited, false, sizeof(isVisited));
    }

    return 0;
}
