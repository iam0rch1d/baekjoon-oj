#include <iostream>

using namespace std;

int main() {
    int n;
    int cuteCount = 0;
    int uncuteCount = 0;

    cin >> n;

    while (n--) {
        int isCute;

        cin >> isCute;

        isCute ? cuteCount++ : uncuteCount++;
    }

    cout << "Junhee is " << (cuteCount < uncuteCount ? "not " : "") << "cute!\n";

    return 0;
}
