#include <cstring>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int commandCounts[10000];
char commands[10000];
int previousRegisters[10000];

int main() {
    int numTestcase;

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        int a;
        int b;
        queue<int> bfsRegisters;

        cin >> a >> b;

        commandCounts[a] = 1;

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
                    cout << commands[tracebackRegisters.top()];

                    tracebackRegisters.pop();
                }

                cout << '\n';

                break;
            }

            int adjacentRegisters[] = {2 * currentRegister % 10000,
                                       (currentRegister + 9999) % 10000,
                                       currentRegister * 10 % 10000 + currentRegister / 1000,
                                       currentRegister % 10 * 1000 + currentRegister / 10};

            for (int i = 0; i < 4; i++) {
                if (!commandCounts[adjacentRegisters[i]]) {
                    commandCounts[adjacentRegisters[i]] = commandCounts[currentRegister] + 1;
                    previousRegisters[adjacentRegisters[i]] = currentRegister;

                    if (i == 0) commands[adjacentRegisters[i]] = 'D';
                    else if (i == 1) commands[adjacentRegisters[i]] = 'S';
                    else if (i == 2) commands[adjacentRegisters[i]] = 'L';
                    else if (i == 3) commands[adjacentRegisters[i]] = 'R';

                    bfsRegisters.push(adjacentRegisters[i]);
                }
            }
        }

        memset(commandCounts, 0, sizeof(commandCounts));
    }

    return 0;
}
