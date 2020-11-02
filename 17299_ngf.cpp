#include <iostream>
#include <stack>

using namespace std;

int a[1000001];
int frequencies[1000001];
int ngf[1000001];

int main() {
    int n;
    stack<int> ngfIndices;

    cin >> n;

    ngfIndices.push(0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        frequencies[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        while (!ngfIndices.empty() && frequencies[a[ngfIndices.top()]] < frequencies[a[i]]) {
            ngf[ngfIndices.top()] = a[i];

            ngfIndices.pop();
        }

        ngfIndices.push(i);
    }

    while (!ngfIndices.empty()) {
        ngf[ngfIndices.top()] = -1;

        ngfIndices.pop();
    }

    for (int i = 1; i <= n; i++) {
        cout << ngf[i] << ' ';
    }

    cout << '\n';

    return 0;
}
