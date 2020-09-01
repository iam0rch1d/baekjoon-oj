#include <iostream>
#include <vector>

#define UNMEMOIZED -1

typedef struct {
    int y;
    int x;
} Point;

using namespace std;

int memoizeMaximumPath(vector<vector<int>> &triangle, vector<vector<int>> &maximumPathCache, Point from) {
    if (from.y == triangle.size() - 1) return triangle[from.y][from.x];

    int &maximumPath = maximumPathCache[from.y][from.x];

    if (maximumPath != UNMEMOIZED) return maximumPath;

    return maximumPath = triangle[from.y][from.x]
                         + max(memoizeMaximumPath(triangle, maximumPathCache, {from.y + 1, from.x}),
                               memoizeMaximumPath(triangle, maximumPathCache, {from.y + 1, from.x + 1}));
}

int main() {
    int triangleSize;

    cin >> triangleSize;

    vector<vector<int>> triangle(triangleSize, vector<int>(triangleSize));
    vector<vector<int>> maximumPathCache(triangleSize, vector<int>(triangleSize, UNMEMOIZED));

    for (int i = 0; i < triangleSize; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    cout << memoizeMaximumPath(triangle, maximumPathCache, {0, 0}) << endl;

    return 0;
}
