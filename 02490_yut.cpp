#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        int backCount = 0;

        for (int j = 0; j < 4; j++) {
            int isBack;

            cin >> isBack;

            backCount += isBack;
        }

        cout << "DCBAE"[backCount] << '\n';
    }

    return 0;
}
