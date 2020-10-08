#include <iostream>

using namespace std;

int n;
int signs[10][10];
int guessings[10];

bool isGuessingValid(int index) {
    int guessingSum = 0;

    for (int i = index; i >= 0; i--) {
        guessingSum += guessings[i];

        if ((signs[i][index] == -1 && guessingSum >= 0)
            || (signs[i][index] == 0 && guessingSum != 0)
            || (signs[i][index] == 1 && guessingSum <= 0)) {
            return false;
        }
    }

    return true;
}

void backtrackGuessings(int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            cout << guessings[i] << ' ';
        }

        cout << '\n';

        exit(0);
    }

    for (int i = 1; i <= 10; i++) {
        guessings[index] = signs[index][index] * i;

        if (isGuessingValid(index)) backtrackGuessings(index + 1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            char sign;

            cin >> sign;

            signs[i][j] = sign == '+' ? 1 : sign == '-' ? -1 : 0;
        }
    }

    backtrackGuessings(0);

    return 0;
}
