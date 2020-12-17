#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> triangles;
    int trianglesSize;
    int tc;

    for (int i = 1; i * (i + 1) < 2000; i++) {
        triangles.push_back(i * (i + 1) / 2);
    }

    trianglesSize = triangles.size();

    cin >> tc;

    while (tc--) {
        int n;
        bool isEureka = false;

        cin >> n;

        for (int i = 0; i < trianglesSize; i++) {
            for (int j = 0; j < trianglesSize; j++) {
                for (int k = 0; k < trianglesSize; k++) {
                    if (triangles[i] + triangles[j] + triangles[k] == n) {
                        isEureka = true;

                        break;
                    }
                }

                if (isEureka) break;
            }

            if (isEureka) break;
        }

        cout << isEureka << '\n';
    }

    return 0;
}
