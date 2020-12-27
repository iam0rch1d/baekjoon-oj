#include <iostream>
#include <stack>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        int m;

        cin >> n >> m;

        if (!n && !m) return 0;

        vvi a(n, vi(m));

        for (vi &ai : a) {
            for (int &aij : ai) {
                cin >> aij;
            }
        }

        vi h(m);
        int ans = 0;

        FOR(i, 0, n) {
            FOR(j, 0, m) {
                if (a[i][j]) h[j]++;
                else h[j] = 0;
            }

            stack<int> sticks;
            int ansTemp = 0;

            FOR(j, 0, m) {
                while (!sticks.empty() && h[sticks.top()] > h[j]) {
                    int height = h[sticks.top()];

                    sticks.pop();

                    int width = j - (sticks.empty() ? 0 : sticks.top() + 1);

                    ansTemp = max(ansTemp, width * height);
                }

                sticks.push(j);
            }

            while (!sticks.empty()) {
                int height = h[sticks.top()];

                sticks.pop();

                int width = m - (sticks.empty() ? 0 : sticks.top() + 1);

                ansTemp = max(ansTemp, width * height);
            }

            ans = max(ans, ansTemp);
        }

        PRINTLN(ans);
    }
}
