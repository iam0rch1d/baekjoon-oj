#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

int n;
int m;

// (<is moved>, <is in hole>)
pair<bool, bool> roll(vector<string> &board, Point &from, unsigned direction) {
    if (board[from.y][from.x] == '.') return {false, true};

    bool isMoved = false;

    while (true) {
        Point to{from.y + "0121"[direction] - '1', from.x + "1210"[direction] - '1'};

        if (board[to.y][to.x] == '#' || board[to.y][to.x] == 'R' || board[to.y][to.x] == 'B') return {isMoved, false};
        else if (board[to.y][to.x] == '.') {
            swap(board[from.y][from.x], board[to.y][to.x]);
            from = to;
            isMoved = true;
        } else if (board[to.y][to.x] == 'O') {
            board[from.y][from.x] = '.';

            return {true, true};
        }
    }
}

int tilt(vector<string> board, vector<unsigned> &directions) {
    Point red;
    Point blue;
    int tiltCount = 0;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (board[i][j] == 'R') red = {i, j};
            else if (board[i][j] == 'B') blue = {i, j};
        }
    }

    for (unsigned direction : directions) {
        bool isRedInHole = false;
        bool isBlueInHole = false;

        tiltCount++;

        while (true) {
            auto redStates = roll(board, red, direction);
            auto blueStates = roll(board, blue, direction);

            if (!redStates.first && !blueStates.first) break;

            if (redStates.second) isRedInHole = true;

            if (blueStates.second) isBlueInHole = true;
        }

        if (isBlueInHole) return 11;

        if (isRedInHole) return tiltCount;
    }

    return 11;
}

int main() {
    int minTiltCount = 11;

    cin >> n >> m;

    vector<string> board(n);

    for (string &boardRow : board) {
        cin >> boardRow;
    }

    for (unsigned tiltBitset = 0; tiltBitset < (1u << 20u); tiltBitset++) {
        unsigned currentBitset = tiltBitset;
        vector<unsigned> directions(10, 4);
        bool areDirectionsValid = true;

        for (int i = 0; i < 10; i++) {
            directions[i] = currentBitset & 3u;

            if (i != 0 && !((directions[i] & 1u) ^ (directions[i - 1] & 1u))) {
                areDirectionsValid = false;

                break;
            }

            currentBitset >>= 2u;
        }

        if (areDirectionsValid) minTiltCount = min(minTiltCount, tilt(board, directions));
    }

    cout << (minTiltCount == 11 ? -1 : minTiltCount) << '\n';

    return 0;
}
