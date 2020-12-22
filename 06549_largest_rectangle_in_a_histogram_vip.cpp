#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        stack<long long> sticks;
        long long ans = 0;

        cin >> n;

        if (n == 0) return 0;

        vector<long long> h(n);

        for (long long &hi : h) {
            cin >> hi;
        }

        for (int i = 0; i < n; i++) {
            while (!sticks.empty() && h[sticks.top()] > h[i]) {
                long long width;
                long long height = h[sticks.top()];

                sticks.pop();

                // <left> = sticks.top() + 1, <right> = i - 1
                width = i - (sticks.empty() ? 0 : sticks.top() + 1);

                ans = max(ans, width * height);
            }

            sticks.push(i);
        }

        while (!sticks.empty()) {
            long long width;
            long long height = h[sticks.top()];

            sticks.pop();

            width = n - (sticks.empty() ? 0 : sticks.top() + 1);

            ans = max(ans, width * height);
        }

        cout << ans << '\n';
    }
}
