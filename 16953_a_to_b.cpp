#include <iostream>

#define INF_MOVES 32

using namespace std;

long long b;

int backtrackMoveFrom(long long a) {
    if (a == b) return 1;
    else if (a > b) return INF_MOVES;

    int adjacentMoves1 = backtrackMoveFrom(a * 2);
    int adjacentMoves2 = backtrackMoveFrom(a * 10 + 1);

    if (adjacentMoves1 == INF_MOVES && adjacentMoves2 == INF_MOVES) return INF_MOVES;

    return min(adjacentMoves1, adjacentMoves2) + 1;
}

int main() {
    long long a;
    int moves;

    cin >> a >> b;

    moves = backtrackMoveFrom(a);

    cout << (moves == INF_MOVES ? -1 : moves) << '\n';

    return 0;
}
