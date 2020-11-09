#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    int m;
    int k;
    int quotient;
    int remainder;

    cin >> n >> m >> k;

    if (n < m + k - 1 || n > m * k) {
        cout << "-1\n";

        return 0;
    }

    for (int i = k; i >= 1; i--) {
        cout << i << ' ';
    }

    if (m - 1) {
        quotient = (n - k) / (m - 1);
        remainder = (n - k) % (m - 1);

        stack<int> lds;

        for (int i = k + 1; i <= n; i++) {
            lds.push(i);

            if (lds.size() == quotient + (remainder > 0)) {
                while (!lds.empty()) {
                    cout << lds.top() << ' ';

                    lds.pop();
                }

                remainder = max(remainder - 1, 0);
            }
        }
    }

    cout << '\n';

    return 0;
}
