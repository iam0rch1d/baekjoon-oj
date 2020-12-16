#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Point;

#define UNKNOWN -1

int memoizeMaxPath(vector<vector<int>> &triangle, vector<vector<int>> &maxPathCache, Point from) {
    if (from.y == triangle.size() - 1) return triangle[from.y][from.x];

    int &maxPath = maxPathCache[from.y][from.x];

    if (maxPath != UNKNOWN) return maxPath;

    return maxPath = triangle[from.y][from.x]
                     + max(memoizeMaxPath(triangle, maxPathCache, {from.y + 1, from.x}),
                           memoizeMaxPath(triangle, maxPathCache, {from.y + 1, from.x + 1}));
}

int main() {
    int triangleSize;

    cin >> triangleSize;

    vector<vector<int>> triangle(triangleSize, vector<int>(triangleSize));
    vector<vector<int>> maxPathCache(triangleSize, vector<int>(triangleSize, UNKNOWN));

    for (int i = 0; i < triangleSize; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    cout << memoizeMaxPath(triangle, maxPathCache, {0, 0}) << '\n';

    return 0;
}
