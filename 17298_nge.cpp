#include <iostream>
#include <stack>

using namespace std;

int a[1000001];
int nge[1000001];

int main() {
    int n;
    stack<int> ngeIndices;

    cin >> n;

    ngeIndices.push(0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        while (!ngeIndices.empty() && a[ngeIndices.top()] < a[i]) {
            nge[ngeIndices.top()] = a[i];

            ngeIndices.pop();
        }

        ngeIndices.push(i);
    }

    while (!ngeIndices.empty()) {
        nge[ngeIndices.top()] = -1;

        ngeIndices.pop();
    }

    for (int i = 1; i <= n; i++) {
        cout << nge[i] << ' ';
    }

    cout << '\n';

    return 0;
}
