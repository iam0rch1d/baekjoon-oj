#include <iostream>
#include <stack>

using namespace std;

int sequence[1000001];
int frequency[1000001];
int ngf[1000001];

int main() {
    int sequenceSize;
    stack<int> ngfIndices;

    cin >> sequenceSize;

    ngfIndices.push(0);

    for (int i = 1; i <= sequenceSize; i++) {
        cin >> sequence[i];

        frequency[sequence[i]]++;
    }

    for (int i = 1; i <= sequenceSize; i++) {
        while (!ngfIndices.empty() && frequency[sequence[ngfIndices.top()]] < frequency[sequence[i]]) {
            ngf[ngfIndices.top()] = sequence[i];

            ngfIndices.pop();
        }

        ngfIndices.push(i);
    }

    while (!ngfIndices.empty()) {
        ngf[ngfIndices.top()] = -1;

        ngfIndices.pop();
    }

    for (int i = 1; i <= sequenceSize; i++) {
        cout << ngf[i] << ' ';
    }

    cout << '\n';

    return 0;
}
