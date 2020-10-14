#include <iostream>
#include <vector>

using namespace std;

int main() {
    int stairsSize;

    cin >> stairsSize;

    vector<int> stairs(stairsSize);
    vector<int> maxPathCache(stairsSize);

    for (int &stair : stairs) {
        cin >> stair;
    }

    maxPathCache[0] = stairs[0];

    if (stairs.size() == 1) {
        cout << maxPathCache[0] << '\n';

        return 0;
    }

    maxPathCache[1] = stairs[1] + stairs[0];

    if (stairs.size() == 2) {
        cout << maxPathCache[1] << '\n';

        return 0;
    }

    maxPathCache[2] = stairs[2] + max(stairs[1], stairs[0]);

    if (stairs.size() == 3) {
        cout << maxPathCache[2] << '\n';

        return 0;
    }

    for (int i = 3; i < stairsSize; i++) {
        maxPathCache[i] = stairs[i] + max(stairs[i - 1] + maxPathCache[i - 3], maxPathCache[i - 2]);
    }

    cout << maxPathCache[stairsSize - 1] << '\n';

    return 0;
}
