#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned n;
    int l;
    int r;
    int x;
    int setCount = 0;

    cin >> n >> l >> r >> x;

    vector<int> a(n);

    for (int &ai : a) {
        cin >> ai;
    }

    sort(a.begin(), a.end());

    for (unsigned aBitset = 0; aBitset < (1u << n); aBitset++) {
        if (__builtin_popcount(aBitset) < 2) continue;

        int lsbIndex = __builtin_ffs((int) aBitset) - 1;
        int msbIndex = -1;
        unsigned tempBitset = aBitset;

        while (tempBitset) {
            msbIndex++;
            tempBitset >>= 1u;
        }

        if (a[msbIndex] - a[lsbIndex] < x) continue;

        int setSum = 0;

        for (unsigned i = lsbIndex; i < n; i++) {
            setSum += (aBitset & (1u << i) ? a[i] : 0);
        }

        setCount += setSum >= l && setSum <= r;
    }

    cout << setCount << '\n';

    return 0;
}
