#include <iostream>
#include <vector>

using namespace std;

int main() {
    int matrixANumRow;
    int matrixANumColumn;
    int matrixBNumColumn;

    cin >> matrixANumRow >> matrixANumColumn;

    vector<vector<int>> matrixA(matrixANumRow, vector<int> (matrixANumColumn));

    for (int i = 0; i < matrixANumRow; i++) {
        for (int j = 0; j < matrixANumColumn; j++) {
            cin >> matrixA[i][j];
        }
    }

    cin >> matrixANumColumn >> matrixBNumColumn;

    vector<vector<int>> matrixB(matrixANumColumn, vector<int> (matrixBNumColumn));
    vector<vector<int>> matrixMultiplication(matrixANumRow, vector<int> (matrixBNumColumn, 0));

    for (int i = 0; i < matrixANumColumn; i++) {
        for (int j = 0; j < matrixBNumColumn; j++) {
            cin >> matrixB[i][j];
        }
    }

    for (int i = 0; i < matrixANumRow; i++) {
        for (int j = 0; j < matrixBNumColumn; j++) {
            for (int k = 0; k < matrixANumColumn; k++) {
                matrixMultiplication[i][j] += matrixA[i][k] * matrixB[k][j];
            }

            cout << matrixMultiplication[i][j] << " ";
        }

        cout << endl;
    }
}
