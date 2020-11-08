#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    string gears[4];
    int k;
    unsigned gearState = 0;

    for (auto &gear : gears) {
        cin >> gear;
    }

    cin >> k;

    while (k--) {
        pair<int, int> initialRotation;
        queue<pair<int, int>> rotations;  // .first = <gear no.>, .second = <direction>
        bool isRotated[] = {false, false, false, false};

        cin >> initialRotation.first >> initialRotation.second;

        initialRotation.first--;

        rotations.push(initialRotation);

        while (!rotations.empty()) {
            int gearNo;
            int direction;

            tie(gearNo, direction) = rotations.front();

            auto &rotatingGear = gears[gearNo];

            rotations.pop();

            for (int i = 0; i < 2; i++) {
                int adjacentGearNo = gearNo + "02"[i] - '1';

                if (adjacentGearNo < 0
                    || adjacentGearNo >= 4
                    || isRotated[adjacentGearNo]
                    || gears[adjacentGearNo]["26"[i] - '0'] == rotatingGear["62"[i] - '0']) {
                    continue;
                }

                rotations.push({adjacentGearNo, -direction});
            }

            if (direction == 1) {
                rotatingGear.insert(rotatingGear.begin(), rotatingGear.back());
                rotatingGear.pop_back();
            } else {
                rotatingGear.push_back(rotatingGear[0]);
                rotatingGear.erase(rotatingGear.begin());
            }

            isRotated[gearNo] = true;
        }
    }

    for (unsigned i = 0; i < 4; i++) {
        gearState |= (((unsigned) gears[i][0] - '0') << i);
    }

    cout << gearState << '\n';

    return 0;
}
