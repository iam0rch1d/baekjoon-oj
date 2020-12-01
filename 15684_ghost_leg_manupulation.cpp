#include <iostream>

using namespace std;

int n;
int m;
int h;
bool ghostlegMap[30][9];

bool isSatisfied() {
    for (int i = 0; i < n; i++) {
        int position = i;

        for (int y = 0; y < h; y++) {
            if (position < n && ghostlegMap[y][position]) position++;
            else if (position > 0 && ghostlegMap[y][position - 1]) position--;
        }

        if (position != i) return false;
    }

    return true;
}

int main() {
    int nh;

    cin >> n >> m >> h;

    nh = --n * h;

    while (m--) {
        int a;
        int b;

        cin >> a >> b;

        --a;
        --b;

        ghostlegMap[a][b] = true;
    }

    if (isSatisfied()) {
        cout << "0\n";

        return 0;
    }

    int minManipulations = 4;

    for (int point1 = 0; point1 < nh; point1++) {
        int y1 = point1 / n;
        int x1 = point1 % n;

        if (ghostlegMap[y1][x1] || (x1 >= 1 && ghostlegMap[y1][x1 - 1]) || (x1 <= n - 2 && ghostlegMap[y1][x1 + 1])) {
            continue;
        }

        ghostlegMap[y1][x1] = true;

        if (isSatisfied()) {
            cout << "1\n";

            return 0;
        }

        for (int point2 = point1 + 2; point2 < nh; point2++) {
            int y2 = point2 / n;
            int x2 = point2 % n;

            if (ghostlegMap[y2][x2]
                || (x2 >= 1 && ghostlegMap[y2][x2 - 1])
                || (x2 <= n - 2 && ghostlegMap[y2][x2 + 1])) {
                continue;
            }

            ghostlegMap[y2][x2] = true;

            if (isSatisfied()) {
                minManipulations = min(minManipulations, 2);
                ghostlegMap[y2][x2] = false;

                break;
            }

            for (int point3 = point2 + 2; point3 < nh; point3++) {
                int y3 = point3 / n;
                int x3 = point3 % n;

                if (ghostlegMap[y3][x3]
                    || (x3 >= 1 && ghostlegMap[y3][x3 - 1])
                    || (x3 <= n - 2 && ghostlegMap[y3][x3 + 1])) {
                    continue;
                }

                ghostlegMap[y3][x3] = true;

                if (isSatisfied()) {
                    minManipulations = min(minManipulations, 3);
                    ghostlegMap[y3][x3] = false;

                    break;
                }

                ghostlegMap[y3][x3] = false;
            }

            ghostlegMap[y2][x2] = false;
        }

        ghostlegMap[y1][x1] = false;
    }

    cout << (minManipulations < 4 ? minManipulations : -1) << '\n';

    return 0;
}
