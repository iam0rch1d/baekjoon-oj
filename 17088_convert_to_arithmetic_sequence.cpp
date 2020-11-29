#include <iostream>
#include <vector>

using namespace std;

int n;

int countOperation(vector<int> b) {
    int difference = b[1] - b[0];
    int operationCount = 0;

    for (int i = 2; i < n; i++) {
        if (b[i] > b[i - 1] + difference + 1 || b[i] < b[i - 1] + difference - 1) return 100001;

        if (b[i] != b[i - 1] + difference) {
            b[i] = b[i - 1] + difference;
            operationCount++;
        }
    }

    return operationCount;
}

int main() {
    cin >> n;

    vector<int> b(n);

    for (int &bi : b) {
        cin >> bi;
    }

    if (n == 1) {
        cout << "0\n";

        return 0;
    }

    int minOperationCount = 100001;

    vector<int> tempB(b);

    for (int i = -1; i <= 1; i++) {
        tempB[0] = b[0] + i;

        for (int j = -1; j <= 1; j++) {
            tempB[1] = b[1] + j;

            minOperationCount = min(minOperationCount, countOperation(tempB) + (i != 0) + (j != 0));
        }
    }

    cout << (minOperationCount == 100001 ? -1 : minOperationCount) << '\n';

    return 0;
}
