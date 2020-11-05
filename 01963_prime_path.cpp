#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int primeCache[] = {2, 3, 5, 7, 11,
                    13, 17, 19, 23, 29,
                    31, 37, 41, 43, 47,
                    53, 59, 61, 67, 71,
                    73, 79, 83, 89, 97};
bool isComposite[10000];
int changes[10000];

int main() {
    int numTestcase;

    for (int primeNumber : primeCache) {
        for (int j = 2; j * primeNumber < 10000; j++) {
            isComposite[j * primeNumber] = true;
        }
    }

    cin >> numTestcase;

    while (numTestcase-- > 0) {
        string oldPassword;
        string newPassword;
        queue<string> bfsPasswords;

        cin >> oldPassword >> newPassword;

        changes[stoi(oldPassword)] = 1;

        bfsPasswords.push(oldPassword);

        while (!bfsPasswords.empty()) {
            string currentPassword = bfsPasswords.front();

            if (currentPassword == newPassword) break;

            bfsPasswords.pop();

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 10; j++) {
                    string adjacentPassword = currentPassword;

                    if (i == 0 && j == 0) continue;

                    int adjacentPasswordNumber;

                    adjacentPassword[i] = j + '0';
                    adjacentPasswordNumber = stoi(adjacentPassword);

                    if (isComposite[adjacentPasswordNumber] || changes[adjacentPasswordNumber]) continue;

                    changes[adjacentPasswordNumber] = changes[stoi(currentPassword)] + 1;

                    bfsPasswords.push(adjacentPassword);
                }
            }
        }

        cout << changes[stoi(newPassword)] - 1 << '\n';

        memset(changes, 0, sizeof(changes));
    }

    return 0;
}
