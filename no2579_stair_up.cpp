#include <iostream>
#include <vector>

using namespace std;

int main() {
    int stairsSize;

    cin >> stairsSize;

    vector<int> stairs(stairsSize);
    vector<int> maximumPathCache(stairsSize);

    for (int &node : stairs) {
        cin >> node;
    }

    maximumPathCache[0] = stairs[0];

    if (stairs.size() == 1) {
        cout << maximumPathCache[0] << endl;

        return 0;
    }

    maximumPathCache[1] = stairs[1] + stairs[0];

    if (stairs.size() == 2) {
        cout << maximumPathCache[1] << endl;

        return 0;
    }

    maximumPathCache[2] = stairs[2] + max(stairs[1], stairs[0]);

    if (stairs.size() == 3) {
        cout << maximumPathCache[2] << endl;

        return 0;
    }

    for (int i = 3; i < stairsSize; i++) {
        maximumPathCache[i] = stairs[i] + max(stairs[i - 1] + maximumPathCache[i - 3], maximumPathCache[i - 2]);
    }

    cout << maximumPathCache[stairsSize - 1] << endl;

    return 0;
}
