#include <iostream>

using namespace std;

int main() {
    int x;
    int y;
    int monthDays[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int monthDayCumulativeSums[12] = {0};

    cin >> x >> y;

    for (int i = 1; i <= 11; i++) {
        monthDayCumulativeSums[i] = monthDayCumulativeSums[i - 1] + monthDays[i - 1];
    }

    switch ((monthDayCumulativeSums[x - 1] + y - 1) % 7) {
        case (0): {
            cout << "MON\n";

            break;
        }
        case (1): {
            cout << "TUE\n";

            break;
        }
        case (2): {
            cout << "WED\n";

            break;
        }
        case (3): {
            cout << "THU\n";

            break;
        }
        case (4): {
            cout << "FRI\n";

            break;
        }
        case (5): {
            cout << "SAT\n";

            break;
        }
        case (6): {
            cout << "SUN\n";

            break;
        }
    }

    return 0;
}
