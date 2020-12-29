#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

#define FOR_(i, x, y) for (int i = (x); i <= (y); i++)
#define PRINT(x) cout << (x) << ' '
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int k;

    cin >> k;

    vi dpa(k + 1, 0);
    vi dpb(k + 1, 0);

    dpa[0] = 1;
    dpb[0] = 0;

    FOR_(i, 1, k) {
        dpa[i] = dpb[i - 1];
        dpb[i] = dpa[i - 1] + dpb[i - 1];
    }

    PRINT(dpa[k]);
    PRINT(dpb[k]);
    PRINTLN("");

    return 0;
}
