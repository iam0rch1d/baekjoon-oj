#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define F first
#define S second

struct Rotation {
    int r;
    int c;
    int s;
};

void rotate(vector<vector<int>> &a, Rotation rotation) {
    vector<vector<int>> belts(rotation.s + 1, vector<int>());
    vector<vector<pair<int, int>>> nextPositionOfBelts(rotation.s + 1, vector<pair<int, int>>());

    for (int i = 1; i <= rotation.s; i++) {
        int beltSize;

        for (int j = rotation.c - i; j < rotation.c + i; j++) {
            belts[i].push_back(a[rotation.r - i][j]);
            nextPositionOfBelts[i].emplace_back(rotation.r - i, j + 1);
        }

        for (int j = rotation.r - i; j < rotation.r + i; j++) {
            belts[i].push_back(a[j][rotation.c + i]);
            nextPositionOfBelts[i].emplace_back(j + 1, rotation.c + i);
        }

        for (int j = rotation.c + i; j > rotation.c - i; j--) {
            belts[i].push_back(a[rotation.r + i][j]);
            nextPositionOfBelts[i].emplace_back(rotation.r + i, j - 1);
        }

        for (int j = rotation.r + i; j > rotation.r - i; j--) {
            belts[i].push_back(a[j][rotation.c - i]);
            nextPositionOfBelts[i].emplace_back(j - 1, rotation.c - i);
        }

        beltSize = belts[i].size();

        for (int j = 0; j < beltSize; j++) {
            a[nextPositionOfBelts[i][j].F][nextPositionOfBelts[i][j].S] = belts[i][j];
        }
    }
}

int main() {
    int n;
    int m;
    int k;
    int minValue = 5001;

    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    vector<Rotation> rotations(k);
    vector<int> rotationIndices(k);

    for (int i = 0; i < k; i++) {
        rotationIndices[i] = i;
    }

    for (auto &ai : a) {
        for (int &aij : ai) {
            cin >> aij;
        }
    }

    for (auto &rotation : rotations) {
        cin >> rotation.r >> rotation.c >> rotation.s;

        rotation.r--;
        rotation.c--;
    }

    while (true) {
        vector<vector<int>> tempA(a);
        int value = 5001;

        for (int i = 0; i < k; i++) {
            rotate(tempA, rotations[rotationIndices[i]]);
        }

        for (int i = 0; i < n; i++) {
            int tempAiSum = 0;

            for (int tempAij : tempA[i]) {
                tempAiSum += tempAij;
            }

            value = min(value, tempAiSum);
        }

        minValue = min(minValue, value);

        if (!next_permutation(rotationIndices.begin(), rotationIndices.end())) {
            cout << minValue << '\n';

            return 0;
        }
    }
}
