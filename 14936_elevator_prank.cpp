#include <iostream>
#include <set>
#include <vector>

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vb>;

#define ALL(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = (x); i < (y); i++)
#define REP(i, x) FOR(i, 0, x)
#define PRINTLN(x) cout << (x) << '\n'

int main() {
    int n;
    int m;

    cin >> n >> m;

    int costs[]{n, n / 2, n - n / 2, (n - 1) / 3 + 1};
    vi totalCosts(1 << 4, 0);
    int sampleSize = min(n, 6);
    vvb samples(1 << 4, vb(sampleSize, false));

    REP(sampleBitset, 1 << 4) {
        REP(i, 4) totalCosts[sampleBitset] += (sampleBitset & (1 << i)) ? costs[i] : 0;

        if (sampleBitset & (1 << 0)) REP(i, sampleSize) samples[sampleBitset][i] = !samples[sampleBitset][i];

        if (sampleBitset & (1 << 1)) {
            for (int i = 1; i < sampleSize; i += 2) {
                samples[sampleBitset][i] = !samples[sampleBitset][i];
            }
        }

        if (sampleBitset & (1 << 2)) {
            for (int i = 0; i < sampleSize; i += 2) {
                samples[sampleBitset][i] = !samples[sampleBitset][i];
            }
        }

        if (sampleBitset & (1 << 3)) {
            for (int i = 0; i < sampleSize; i += 3) {
                samples[sampleBitset][i] = !samples[sampleBitset][i];
            }
        }
    }

    set<vb> possibleSamples;

    REP(i, 1 << 4) if (totalCosts[i] <= m) possibleSamples.insert(samples[i]);

    PRINTLN(possibleSamples.size());

    return 0;
}
