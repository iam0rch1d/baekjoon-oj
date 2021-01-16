#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vi = vector<int>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINTLN(x) cout << (x) << '\n'

#define MODULO 1000000007

template<typename T>
void chmodadd(T &x, T q) { x = (x + q) % MODULO; }

template<typename T>
void chmodsub(T &x, T q) { x = (x - q + MODULO) % MODULO; }

vi factorsOf[100001];
ll dp[11][100001];
ll dpSum[11];

int main() {
    int n;
    int k;

    cin >> n >> k;

    FOR_(i, 1, k) {
        for (int j = i * 2; j <= k; j += i) {
            factorsOf[j].push_back(i);
        }
    }

    FOR_(i, 1, k) dp[1][i] = 1;

    dpSum[1] = k;

    FOR_(i, 2, n) {
        FOR_(j, 1, k) {
            dp[i][j] = dpSum[i - 1];

            for (int factor : factorsOf[j]) {
                chmodsub(dp[i][j], dp[i - 1][factor]);
            }

            chmodadd(dpSum[i], dp[i][j]);
        }
    }

    PRINTLN(dpSum[n]);

    return 0;
}
