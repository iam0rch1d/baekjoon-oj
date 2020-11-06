#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

int pushSwitches(vector<unsigned> isDifferent) {
    int pushCount = 0;

    for (int i = 0; i <= n - 2; i++) {
        if (isDifferent[i]) {
            for (int j = 0; j <= 2; j++) {
                if (i + j < n) isDifferent[i + j] ^= 1u;
            }

            pushCount++;
        }
    }

    return all_of(isDifferent.begin(), isDifferent.end(), [](unsigned i){ return !i; }) ? pushCount : 100001;
}

int main() {
    string currentLights;
    string targetLights;
    int minPushCount = 100001;

    cin >> n >> currentLights >> targetLights;

    vector<unsigned> isDifferent(n);

    for (int i = 0; i < n; i++) {
        isDifferent[i] = currentLights[i] != targetLights[i];
    }

    minPushCount = min(minPushCount, pushSwitches(isDifferent));

    isDifferent[0] ^= 1u;
    isDifferent[1] ^= 1u;

    minPushCount = min(minPushCount, 1 + pushSwitches(isDifferent));

    cout << (minPushCount == 100001 ? -1 : minPushCount) << '\n';

    return 0;
}
