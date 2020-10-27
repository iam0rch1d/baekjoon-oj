#include <cstring>
#include <iostream>

#define MAX_SIZE 50

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

Point operator+(Point a, Point b) {
    return {a.y + b.y, a.x + b.x};
}

int n;
int m;
string board[MAX_SIZE];
int cyclicCircleCount[MAX_SIZE][MAX_SIZE];
const Point differences[] = {{0,  -1},
                             {1,  0},
                             {-1, 0},
                             {0,  1}};

bool dfsCycle(Point current, int count, char color) {
    if (cyclicCircleCount[current.y][current.x]) return count - cyclicCircleCount[current.y][current.x] >= 4;

    cyclicCircleCount[current.y][current.x] = count;

    for (Point difference : differences) {
        Point adjacent = current + difference;

        if (adjacent.y < 0 || adjacent.y >= n || adjacent.x < 0 || adjacent.x >= m) continue;

        if (board[adjacent.y][adjacent.x] == color && dfsCycle(adjacent, count + 1, color)) {
            cout << "Yes\n";

            exit(0);
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfsCycle({i, j}, 1, board[i][j]);
            memset(cyclicCircleCount, 0, sizeof(cyclicCircleCount));
        }
    }

    cout << "No\n";

    return 0;
}
