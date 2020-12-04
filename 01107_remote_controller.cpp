#include <iostream>

#define INF_CLICK_COUNT 500001

using namespace std;

int target;
bool isButtonBroken[10];

int calculateClickCount(int channel) {
    if (channel == 0) return isButtonBroken[0] ? INF_CLICK_COUNT : 1;
    else if (channel == 100) return 0;

    int clickCount = 0;

    while (channel > 0) {
        if (isButtonBroken[channel % 10]) return INF_CLICK_COUNT;

        channel /= 10;
        clickCount++;
    }

    return clickCount;
}

int main() {
    int numBrokenButton;
    int minClickCount = INF_CLICK_COUNT;

    cin >> target >> numBrokenButton;

    while (numBrokenButton-- > 0) {
        int brokenButton;

        cin >> brokenButton;

        isButtonBroken[brokenButton] = true;
    }

    for (int i = 0; i <= 1000000; i++) {
        minClickCount = min(minClickCount, calculateClickCount(i) + abs(target - i));
    }

    cout << minClickCount << '\n';

    return 0;
}
