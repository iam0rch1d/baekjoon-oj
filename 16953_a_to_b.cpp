#include <iostream>

#define MAX_MOVES 32

using namespace std;

long long b;

int backtrackMoveFrom(long long a) {
    if (a == b) return 1;
    else if (a > b) return MAX_MOVES;

    int adjacentMoves1 = backtrackMoveFrom(a * 2);
    int adjacentMoves2 = backtrackMoveFrom(a * 10 + 1);

    if (adjacentMoves1 == MAX_MOVES && adjacentMoves2 == MAX_MOVES) return MAX_MOVES;

    return min(adjacentMoves1, adjacentMoves2) + 1;
}

int main() {
    long long a;
    int moves;

    cin >> a >> b;

    moves = backtrackMoveFrom(a);

    cout << (moves == MAX_MOVES ? -1 : moves) << '\n';

    return 0;
}
